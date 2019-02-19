//A code that bounds an image within a bounding box
//Written 11 April 2017
//By Pranav Singh z3461857 (and lab partner Matthew Chooeu)
//For COMP1511 Lab07 and Assignment 1

#include <stdio.h>
#include "captcha.h"

void get_bounding_box(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width) {

    int i = 0;
    int j = 0;
    int endRow = 0;
    int endColumn = 0; 
    int rowReturn = 0; 
    int columnReturn = 0;

    //Checking row start
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {

            //Checks for where the black pixels start
            if (pixels[i][j] == 1) {
                
                //Creating a variable so that it never assigns start_row more than once                
                if (rowReturn == 0) {
                    *start_row = i;
                    rowReturn = 1;
                }
                endRow = i;
                break;
            }
        }
    }

    //Calculates box_height
    *box_height= endRow - *start_row + 1; 

    //Checking column start
    for(j = 0; j < width; j++) {
        for(i = 0; i < height; i++) {

            //Checks for where the black pixels start
            if (pixels[i][j]==1) {
                
                //Crating a variable so that it never assigns start_column more than once
                if (columnReturn == 0) {
                    *start_column = j;
                    columnReturn = 1;
                }
                endColumn = j;
                break;
            }
        }
    }

    //Calculates box_width
    *box_width= endColumn - *start_column + 1; 
}
