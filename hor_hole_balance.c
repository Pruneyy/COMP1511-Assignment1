//A program to calculate the horizontal balance of the holes in an image
//Written 25 April 2017
//By Pranav Singh z3461857
//For COMP1511 Assignment 1

#include <stdio.h>
#include "captcha.h"

double get_hor_hole_balance(int height, int width, int pixels[height][width]) {

    int i = 0;
    int j = 0;
    double column_sum = 0;
    double current_column = 0;
    double no_white_pixels = 0;
    double hor_hole_balance = 0;
    double hole_pixels_column = 0;

    //Call holes function first to properly populate the array
    holes(height, width, pixels);

    //Go through width
    for (i = 0; i < width; i++) {
        //Go through height        
        for (j = 0; j < height; j++) {
            //Checks for holes            
            if (pixels[j][i] == 0) {
                hole_pixels_column++;
            }
        }

        //Necessary calculations to find horizontal balance
        no_white_pixels += hole_pixels_column;
        column_sum += current_column * hole_pixels_column;
        hole_pixels_column = 0;
        current_column++;
    }

    //Final calculation to find the horizontal balance of holes
    hor_hole_balance = (column_sum / no_white_pixels + 0.5) / width;

    return hor_hole_balance;
}
