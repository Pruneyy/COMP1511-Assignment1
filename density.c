//A program to calculate the density of black pixels in an image
//Written 19 April 2017
//By Pranav Singh z3461857
//For COMP1511 Assignment 1

#include <stdio.h>
#include "captcha.h"

double get_density(int height, int width, int pixels[height][width]) {

    int x = 0;
    int y = 0;
    double no_black_pixels = 0;
    double black_pixels_row = 0;
    double density = 0;

    //Looping through array to find black pixels
    for (x = 0; x < height; x++) {
        for (y = 0; y < width; y++) {
            if (pixels[x][y] == 1) {
                black_pixels_row++;
            }
        }

        //Calculating relevant parameters to find density
        no_black_pixels += black_pixels_row;
        black_pixels_row = 0;

    }
    
    //Density calculation
    density = no_black_pixels/(width * height);
    
    return density;
}
