//A program to calculate the number of "fake holes" (essentially curves or overhangs that aren't holes) in an image
//Written 29 April 2017
//By Pranav Singh z3461857
//For COMP1511 Assignment 1

#include <stdio.h>
#include "captcha.h"
#include <math.h>


double fake_hole(int height, int width, int pixels[height][width]) {
    int x = 0;  //Height 
    int y = 0;  //Width
    int j = 0;  //Counter for number of holes
    int p[height][width];
    int numberHoles[height];
    int nomberHoles[height];
    int max = 0;
    int max_one = 0;
    int max_two = 0;
    int h = 0;

    h = 0.5 * height;
    
    //Initialising array 'p' to 0
    for (x = 0; x < height; x++) {
        for (y = 0; y < width; y++) {
            p[x][y] = 0;
        }
    }

    //Initialising arrays numberHoles and nomberHoles to 0    
    for (x = 0; x < height; x++) {
        numberHoles[x] = 0;
        nomberHoles[x] = 0;
    }

        //Starting at top left corner of image
        for(x = height-1; x >= 0; x--) {
            for(y = 0; y < width; y++) {
        
                //Assigning border pixels to value 9
                if (x == 0 || x == (height-1) || y == 0 || y == (width-1)) {
                    p[x][y] = 9;

                //Checking pixels around current pixels to see if they are linked            
                } else if (pixels[x][y] == 0) {
                    if ((p[x][y + 1] == 9 || p[x][y - 1] == 9)) {
                        p[x][y] = 9;                          
                    } else {
                        p[x][y] = 0;
                    }

                //Leave black pixels as value 1
                }else{
                    p[x][y] = 1;
                }

            }         
        } 

        //Starting at top right corner, otherwise identical to first loop
        for(x = height-1; x >= 0; x--) {
            for(y = width - 1; y >= 0; y--) {
                if (x == 0 || x == (height-1) || y == 0 || y == (width-1)) {
                    p[x][y] = 9;        
                } else if (pixels[x][y] == 0) {
                    if ((p[x][y + 1] == 9 || p[x][y - 1] == 9)) {
                        p[x][y] = 9;                          
                    } else {
                        p[x][y] = 0;
                    }
                }else{
                    p[x][y] = 1;
                }

            }         
        }

    //Counting holes in the top half of the image and assigning to array nomberHoles
    for(y = 0; y < width; y++) {
        j = 0;
        for(x = height-1; x >= h; x--) {  
            if (p[x][y] == 0) {
                if (p[x - 1][y] == 1 || p[x + 1][y] == 1) {
                j++;
                nomberHoles[x] = j;                
                }
            }
        }
     }

    //Counting holes in the bottom half of the image and assigning to array numberHoles
    for(y = 0; y < width; y++) {
        j = 0;
        for(x = 0; x < h; x++) {  
            if (p[x][y] == 0) {
                if (p[x - 1][y] == 1 || p[x + 1][y] == 1) {
                j++;
                numberHoles[x] = j;                
                }
            }
        }
     }

    //Finding the max of the first array
    max_one = 0;
    for(x = 0; x < height; x++) {
        if (numberHoles[x] > max_one) {
            max_one = numberHoles[x];
        }
    }

    //Finding the max of the second array
    max_two = 0;
    for(x = 0; x < height; x++) {
        if (nomberHoles[x] > max_two) {
            max_two = nomberHoles[x];
        }
    }

    max = max_one + max_two;
    return max;
}
