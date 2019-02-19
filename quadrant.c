//A program to calculate the density and width of each quadrant in an image
//Written 22 April 2017
//By Pranav Singh z3461857 
//For COMP1511 Assignment 1

#include <stdio.h>
#include "captcha.h"

void get_quadrant_density(int height, int width, int pixels[height][width], double *density_one, double *density_two, double *density_three, double *density_four, int *wide) {

    int x = 0;
    int y = 0;
    int h = 0;
    int w = 0;
    int whyd = 0;   //Variable for width (width had been used far too often and was getting confusing - hence whyd (like wide :D))
    double no_black_pixels_one = 0;
    double no_black_pixels_two = 0;
    double no_black_pixels_three = 0;
    double no_black_pixels_four = 0;
    double black_pixels_row_one = 0;
    double black_pixels_row_two = 0;
    double black_pixels_row_three = 0;
    double black_pixels_row_four = 0;
    double d_one = 0;
    double d_two = 0;
    double d_three = 0;
    double d_four = 0;

    h = (0.5 * height);
    w = (0.5 * width);

    //Following 4 loops split the image into 4 equal quadrants and returns the black pixel density for each quadrant

    //Quadrant 1
    for (x = (height - 1); x >= h; x--) {
        for (y = 0; y < w; y++) {
            if (pixels[x][y] == 1) {
                black_pixels_row_one++;
            }
        }

        no_black_pixels_one += black_pixels_row_one;
        black_pixels_row_one = 0;
    }

    //Quadrant 2
    for (x = (height - 1); x >= h; x--) {
        for (y = (width - 1); y >= w; y--) {
            if (pixels[x][y] == 1) {
                black_pixels_row_two++;
            }
        }

        no_black_pixels_two += black_pixels_row_two;
        black_pixels_row_two = 0;
    }

    //Quadrant 3
    for (x = 0; x < h; x++) {
        for (y = 0; y < w; y++) {
            if (pixels[x][y] == 1) {
                black_pixels_row_three++;
            }
        }

        no_black_pixels_three += black_pixels_row_three;
        black_pixels_row_three = 0;
    }

    //Quadrant 4
    for (x = 0; x < h; x++) {
        for (y = (width - 1); y >= w; y--) {
            if (pixels[x][y] == 1) {
                black_pixels_row_four++;
            }
        }

        no_black_pixels_four += black_pixels_row_four;
        black_pixels_row_four = 0;
    }

    x = 0;
    y = 0;

    //A while loop (as suggested by a tutor during a help session) to find the width of an image in the bottom two quadrants
    //Note: The while loop was suggested in place of a for loop in order to easily end the loop at x = h
    while (x < h) {
        if (pixels[x][y] == 1) {
            x = x + 2;
            while (y < (width - 1)) {
                if ((pixels[x][y] == 1) && (pixels[x][y+1] == 1)) {
                    whyd++;
                }
                y++;
            }
            x = h;
        }
        x++;
    }
                
    //Calculating densities
    d_one = no_black_pixels_one / (h * w);
    d_two = no_black_pixels_two / (h * w);
    d_three = no_black_pixels_three / (h * w);
    d_four = no_black_pixels_four / (h * w);

    //Assigning relevant values to pointers
    *density_one = d_one;
    *density_two = d_two;
    *density_three = d_three;
    *density_four = d_four;
    *wide = whyd;    

}
