//A program that copies an array (pixels[height][width]) to a new array 
//Written 11 April 2017
//By Pranav Singh z3461857 (and lab partner Matthew Chhoeu)
//For COMP1511 Lab07 and Assignment 1

#include <stdio.h>
#include "captcha.h"


void copy_pixels(int height, int width, int pixels[height][width],
                 int start_row, int start_column, int copy_height, int copy_width,
                 int copy[copy_height][copy_width]) {

    int i = 0;
    int j = 0;
    int k = 0;
    
        //Loop through height
        for (i = 0; i < copy_height; i++) {

            //Loop through column
            for(j = start_column; j < (start_column+copy_width); j++) {

                //Copy array across
                copy[i][k] = pixels[start_row][j];                          
                k++;
            }

            k = 0;
            start_row++;

        }
}
