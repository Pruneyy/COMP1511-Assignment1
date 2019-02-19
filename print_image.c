//A program to convert white spaces to '.' and black spaces to '*'
//Written April 11 2017
//By Pranav Singh z3461857
//For COMP1511 Lab07

#include <stdio.h>
#include "captcha.h"

void print_image(int height, int width, int pixels[height][width]) {
    int x = 0;  //height 
    int y = 0;  //width

    //Loop going through height
    for(x = height-1; x >=0; x--) {

        //Loop going through width
        for(y = 0; y < width; y++) {

            //if (pixels[x][y] == 0 && (pixels[x + 1][y] == 1 || pixels[x - 1][y] == 1 || pixels[x][y + 1] == 1 || pixels[x][y - 1] == 1)) {
            //    printf("+");
            //}
            //Checking for black pixels
            if(pixels[x][y] == 1) {
                printf("*");

            //Checking for white pixels    
            } else {
                printf(".");
            }
        }
        //Printing new line after width loop
        printf("\n");
       
    }
}


