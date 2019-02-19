//A program to count the amount of times a vertical line will pass through the image
//Written 27 April 2017
//By Pranav Singh z3461857
//For COMP1511 Assignment 1

#include <stdio.h>
#include "captcha.h"

int get_lines(int height, int width, int pixels[height][width]) {

    int x = 0;
    int y = 0;
    int lines = 0;
    int start_row = 0;
    int box_width = 0;
    int box_height = 0;
    int half_width = 0;
    int start_column = 0;

    //Call bounding box function to ensure vertical line test is in center of image
    get_bounding_box(height, width, pixels, &start_row, &start_column, &box_height, &box_width);

    half_width = box_width / 2.0;

    //Looping through the height at a width of half the box width and counting the amount of times a pixel of value 1 is crossed
    for (x = start_row; x < (box_height - 1); x++) {
        if (pixels[x][half_width] == 1) {
            if (pixels[x + 1][half_width] == 0) {
                lines++;
            }
        }
    }

    return lines;
}


    
