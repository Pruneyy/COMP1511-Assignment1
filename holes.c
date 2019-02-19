//A program to calculate the number of holes in an image
//Written 21 April 2017
//By Pranav Singh z3461857
//For COMP1511 Assignment 1

#include <stdio.h>
#include "captcha.h"
#include <math.h>

double holes(int height, int width, int pixels[height][width]) {
    int x = 0;  //Height 
    int y = 0;  //Width
    int i = 0;  //Loop counter
    int j = 0;  //Hole counter
    int m = 0;  //0 hole counter
    int n = 0;  //1 hole counter
    int p = 0;  //2 hole counter
    int h[height][width];
    int numberHoles[height];
    int hole = 0;
    int max = 0;

    
    //Initialising array 'h' to 0
    for (x = 0; x < height; x++) {
        for (y = 0; y < width; y++) {
            h[x][y] = 0;
        }
    }

    //Initialising array 'numberHoles' to 0   
    for (x = 0; x < height; x++) {
        numberHoles[x] = 0;
    }

    //Running the entire loop 'i' times (in this case, twice)
    for (i = 0; i < 2; i++) {

        //Starting at top left corner of image
        for(x = height-1; x >= 0; x--) {
            for(y = 0; y < width; y++) {
        
                //Assigning border pixels to value 9
                if (x == 0 || x == (height-1) || y == 0 || y == (width-1)) {
                    h[x][y] = 9;

                //Checking pixels around current pixels to see if they are linked            
                } else if (pixels[x][y] == 0) {
                    if ((h[x + 1][y] == 9 || h[x - 1][y] == 9 || h[x][y + 1] == 9 || h[x][y - 1] == 9)) {
                        h[x][y] = 9;                          
                    } else {
                        h[x][y] = 0;
                    }

                //Leave black pixels as value 1
                } else {
                    h[x][y] = 1;
                }

            }         
        } 

        //Starting at top right corner, otherwise identical to first loop
        for(x = height-1; x >= 0; x--) {
            for(y = width - 1; y >= 0; y--) {
                if (x == 0 || x == (height-1) || y == 0 || y == (width-1)) {
                    h[x][y] = 9;        
                } else if (pixels[x][y] == 0) {
                    if ((h[x + 1][y] == 9 || h[x - 1][y] == 9 || h[x][y + 1] == 9 || h[x][y - 1] == 9)) {
                        h[x][y] = 9;                          
                    } else {
                        h[x][y] = 0;
                    }
                } else {
                    h[x][y] = 1;
                }

            }         
        }

        //Starting at top left corner but going vertically instead of horizontally
        for(y = 0; y < width; y++) {
            for(x = height-1; x >= 0; x--) {
                if (x == 0 || x == (height-1) || y == 0 || y == (width-1)) {
                    h[x][y] = 9;        
                } else if (pixels[x][y] == 0) {
                    if ((h[x + 1][y] == 9 || h[x - 1][y] == 9 || h[x][y + 1] == 9 || h[x][y - 1] == 9)) {
                        h[x][y] = 9;                          
                    } else {
                        h[x][y] = 0;
                    }
                } else {
                    h[x][y] = 1;
                }

            }         
        }

        //Starting at bottom left corner and going vertically instead of horizontally
        for(y = width - 1; y >= 0; y--) {
            for(x = 0; x < height; x++) {
                if (x == 0 || x == (height-1) || y == 0 || y == (width-1)) {
                    h[x][y] = 9;        
                } else if (pixels[x][y] == 0) {
                    if ((h[x + 1][y] == 9 || h[x - 1][y] == 9 || h[x][y + 1] == 9 || h[x][y - 1] == 9)) {
                        h[x][y] = 9;                          
                    } else {
                        h[x][y] = 0;
                    }
                } else {
                    h[x][y] = 1;
                }

            }         
        }

        //Starting at top left corner
        for(x = height-1; x >= 0; x--) {
            for(y = 0; y < width; y++) {
                if (x == 0 || x == (height-1) || y == 0 || y == (width-1)) {
                    h[x][y] = 9;

                //Checking for any singular 0's surrounded by 1's created in the image (as seen in image 6_12.pbm)
                } else if (pixels[x][y] == 0) {
                    if ((h[x + 1][y] == 1 && h[x - 1][y] == 1 && h[x][y + 1] == 1 && h[x][y - 1] == 1)) {
                        h[x][y] = 1;                          
                    }
                }         
            }
        }
    }   
    

    //Checks all vertical lines for amount of changes from 0 to 1 and adds them to array numberHoles  
    for(y = 0; y < width; y++) {
        j = 0;
        for(x = height-1; x >= 0; x--) {  
            if (h[x][y] == 0) {
                if (h[x - 1][y] == 1) {
                j++;
                numberHoles[x] = j;                
            }
            }
        }
     }

    //Counting how many times the loop counts 0, 1 or 2 holes in an image
    for(x = 0; x < height; x++) {
        if (numberHoles[x] == 0) {
            m++;
        } else if (numberHoles[x] == 1) {
            n++;
        } else if (numberHoles[x] == 2) {
            p++;
        }
    }

    //Finds max number of holes in array numberHoles
    for(x = 0; x < height; x++) {
        if (numberHoles[x] > max) {
            max = numberHoles[x];
        }
    }

    //Correcting for any errors (i.e. if it only finds 2 holes once in the entire image, there is clearly an outlier point or points messing up the check)   
    if (max == 2) {
        if (p < 2) {
            max = 1;
        }
    } else if (max == 1) {
        if (n < 2) {
            max = 0;
        }
    }
 
    hole = max;
    return hole;
}

   

