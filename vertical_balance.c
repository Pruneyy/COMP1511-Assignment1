//A program to calculate the vertical balance of an image
//Written 14 April 2017
//By Pranav Singh z3461857
//For COMP1511 Assignment 1

#include <stdio.h>
#include "captcha.h"

double get_vertical_balance(int height, int width, int pixels[height][width]) {

    int x = 0;
    int y = 0;
    double row_sum = 0;
    double current_row = 0;
    double no_black_pixels = 0;
    double black_pixels_row = 0;
    double vertical_balance = 0;

    //Loop through height
    for (x = 0; x < height; x++) {
        
        //Loop through width
        for (y = 0; y < width; y++) {

            //Check for black pixel
            if (pixels[x][y] == 1) {
                black_pixels_row++;
            }
        }

        //Calculating necessary parameters
        no_black_pixels += black_pixels_row;
        row_sum += current_row * black_pixels_row;
        black_pixels_row = 0;
        current_row++;
    }

    //Final vertical balance calculation
    vertical_balance = (row_sum / no_black_pixels + 0.5) / height;

    return vertical_balance;
}
