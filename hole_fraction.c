//A program to calculate the hole fraction in an image
//Written 29 April 2017
//By Pranav Singh z3461857
//For COMP1511 Assignment 1

#include <stdio.h>
#include "captcha.h"

void hole_fraction(int height, int width, int pixels[height][width], double *top_hole_fraction, double *bottom_hole_fraction) {

    int x = 0;
    int y = 0;
    int h = 0;
    double no_white_pixels = 0;
    double hole_pixels_row = 0;
    double top_hole = 0;
    double bottom_hole = 0;

    //Call holes function to properly populate array
    holes(height, width, pixels);
    h = 0.5 * height;

    //Finds hole fraction in bottom half of image
    for (x = 0; x < h; x++) {
        for (y = 0; y < width; y++) {
            if (pixels[x][y] == 0) {
                hole_pixels_row++;
            }
        }
        
        //Calculating density of holes compared to rest of image
        no_white_pixels += hole_pixels_row;
        hole_pixels_row = 0;
    }

    bottom_hole = no_white_pixels/(width * height);

    //Reassigns reused variables to 0
    hole_pixels_row = 0;
    no_white_pixels = 0;

    //Finds hole fraction in top half of image
    for (x = (height - 1); x >= h; x--) {
        for (y = 0; y < width; y++) {
            if (pixels[x][y] == 0) {
                hole_pixels_row++;
            }
        }

        //Calculating density of hole compared to rest of image
        no_white_pixels += hole_pixels_row;
        hole_pixels_row = 0;
    }

    top_hole = no_white_pixels/(width * height);

    //Assigning relevant calculations to pointers
    *top_hole_fraction = top_hole;
    *bottom_hole_fraction = bottom_hole;
}
