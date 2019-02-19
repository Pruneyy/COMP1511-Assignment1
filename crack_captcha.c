//A program to read and attempt to decipher a four number captcha image
//Written 29 April 2017
//By Pranav Singh z3461857
//For COMP1511 Assignment 1

#include <stdio.h>
#include "captcha.h"

int main(int argc, char *argv[]) {

    int w = 0;
    int row = 0;
    int wide = 0;
    int lines = 0;
    int width = 0;
    int with = 50;
    int height = 0;
    int start_row = 0;
    int box_width = 0;
    int box_height = 0;
    int fake_holes = 0;
    int start_column = 0;
    double hole = 0;
    double d_one = 0;
    double d_two = 0;
    double d_four = 0;
    double d_three = 0;
    double density = 0;
    double hor_hole = 0;
    double top_hole = 0;
    double h_balance = 0;
    double v_balance = 0;
    double vert_hole = 0;
    double bottom_hole = 0;

    //This section (up to box_pixels) is taken from the Lab07 test_print_image code - (assumed to be written by Andrew Taylor)
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return 1;
    }

    if (get_pbm_dimensions(argv[1], &height, &width) != 1) {
        return 1;
    }

    int pixels[height][width];
    if (read_pbm(argv[1], height, width, pixels)) {

        for (w = 0; w < width; w+=50) {
            int smaller_pixels[height][with];
            //Calls copy_pixels function to copy the pixels array to 4 smaller equal sized arrays [height][50]
            copy_pixels(height, width, pixels, row, w, height, with, smaller_pixels);

            //Calls bounding box
            get_bounding_box(height, with, smaller_pixels, &start_row, &start_column, &box_height, &box_width);

            //Calls copy_pixels to copy the new smaller pixels array to the bounding box sized array
            int box_pixels[box_height][box_width];
            copy_pixels(height, with, smaller_pixels, start_row, start_column, box_height, box_width, box_pixels);

            //This block calls all the relevant functions
            hole = holes(box_height, box_width, box_pixels);
            h_balance = get_horizontal_balance(box_height, box_width, box_pixels);
            v_balance = get_vertical_balance(box_height, box_width, box_pixels);
            density = get_density(box_height, box_width, box_pixels);
            get_quadrant_density(box_height, box_width, box_pixels, &d_one, &d_two, &d_three, &d_four, &wide);
            lines = get_lines(box_height, box_width, box_pixels);
            vert_hole = get_vert_hole_balance(box_height, box_width, box_pixels);
            hor_hole = get_hor_hole_balance(box_height, box_width, box_pixels);
            fake_holes = fake_hole(box_height, box_width, box_pixels);
            hole_fraction(box_height, box_width, box_pixels, &top_hole, &bottom_hole);


            //For 8
            if (hole == 2) {
                printf("8");

            //For 1, 2, 3, 5, 7
            } else if (hole == 0) {

                //Fake holes < 2
                if (fake_holes < 2 && lines > 2) {
                    printf("2");
                } else if (fake_holes < 2 && lines == 2) {
                    if (v_balance < 0.53) {
                        printf("2");
                    } else {
                        printf("7");
                    }
                } else if (fake_holes < 2 && lines < 2) {
                    if (v_balance < 0.53) {
                        printf("1");
                    } else {
                        printf("7");
                    }                

                //Fake holes > 2
                } else if (fake_holes > 2) {
                    if (((h_balance > 0.5) || (v_balance > 0.5)) && (d_two > d_one)){
                        printf("3");
                    } else {
                        printf("5");
                    }

                //Fake holes = 2
                } else if (fake_holes == 2) {
                    if (lines < 2) {
                        printf("1");
                    } else if (lines > 2) {
                        if (h_balance > 0.5 && v_balance < 0.5 && (d_two > d_one)) {
                            printf("2");
                        } else if (((h_balance > 0.5) || (v_balance > 0.5)) && (d_two > d_one)){
                            printf("3");
                        } else {
                            printf("5");
                        }
                        
                    } else if (lines == 2) {
                        if ((h_balance < 0.5) && (v_balance < 0.5) && (density < 0.5)) {
                            printf("1");
                        } else if (h_balance > 0.5 && v_balance < 0.5 && (d_two > d_one)) {
                            printf("2");
                        } else if (((h_balance > 0.5) || (v_balance > 0.5)) && (d_two > d_one)){
                            if (density > 0.4) {
                                printf("3");
                            }
                        } else {
                            printf("5");
                        }
                    }
                } else {
                    printf("3");
                }
            

            //For 0, 4, 6, 9
            } else if (hole == 1) {
                if (lines == 1) {
                    if ((((h_balance > 0.5 && (wide >= 10)) || ((wide >= 10) && (v_balance < 0.5))) && (density < 0.5)) || (vert_hole > 0.5 && hor_hole < 0.5)) {
                        printf("4");
                    } else {
                        printf("0");
                    }             
                } else if ((((h_balance < 0.5) && (v_balance < 0.5)) && ((d_three > d_two) || (d_two < d_one && d_three && d_four))) || (vert_hole > 0.5 && hor_hole > 0.5)) {
                    printf("6");
                } else if ((((h_balance > 0.5 && (wide >= 10)) || ((wide >= 10) && (v_balance < 0.5))) && (density < 0.5)) || (vert_hole > 0.5 && hor_hole < 0.5)) {
                    printf("4");
                } else if ((v_balance > 0.5) || (d_three < (d_one && d_two && d_four)) || (vert_hole < 0.5 && hor_hole > 0.5)) {
                    printf("9");
                } else {
                    printf("0");
                }

            } else if (hole > 2) {
                printf("8");
            }

        }

    //Print new line after the 4 numbers
    printf("\n");

    }

    return 0;
}
