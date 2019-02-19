//A program to calculate the vertical balance of a hole
//Written 25 April 2017
//By Pranav Singh z3461857
//For COMP1511 Assignment 1

#include <stdio.h>
#include "captcha.h"

double get_vert_hole_balance(int height, int width, int pixels[height][width]) {

    int x = 0;
    int y = 0;
    double row_sum = 0;
    double current_row = 0;
    double no_white_pixels = 0;
    double hole_pixels_row = 0;
    double vert_hole_balance = 0;

    //Call holes function first to populate the array properly
    holes(height, width, pixels);

    //Loop through height and width and apply normal vertical balance check but for pixels of value 0 (holes) instead of pixels of value 1 (the number)
    for (x = 0; x < height; x++) {
        for (y = 0; y < width; y++) {
            if (pixels[x][y] == 0) {
                hole_pixels_row++;
            }
        }

        //Calculating necessary parameters for vertical balance calculation
        no_white_pixels += hole_pixels_row;
        row_sum += current_row * hole_pixels_row;
        hole_pixels_row = 0;
        current_row++;
    }

    //Final vertical balance calculation
    vert_hole_balance = (row_sum / no_white_pixels + 0.5) / height;

    return vert_hole_balance;
}
