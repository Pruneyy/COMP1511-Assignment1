//A program to calculate the horizontal balance of an image
//Written 11 April 2017
//By Pranav Singh z3461857 (and lab partner Matthew Chhoeu)
//For COMP1511 Lab07 and Assignment 1

#include <stdio.h>
#include "captcha.h"

double get_horizontal_balance(int height, int width, int pixels[height][width]) {

    int i = 0;
    int j = 0;
    double column_sum = 0; 
    double current_column = 0;
    double n_black_pixels = 0;
    double horizontal_balance = 0; 
    double black_pixels_column = 0;
     
    //Go through width
    for (i = 0; i < width; i++) {
        //Go through height        
        for (j = 0; j < height; j++) {
            //Checks for black pixel            
            if (pixels[j][i] == 1) {
                black_pixels_column++;
            }
        }

        //Calculation given to find parameters for horizontal balance
        n_black_pixels += black_pixels_column;
        column_sum += current_column * black_pixels_column;
        black_pixels_column = 0;
        current_column++;
    }
      
    //Given formula for horizontal balance
    horizontal_balance = (column_sum / n_black_pixels + 0.5) / width;

    return horizontal_balance;

}
