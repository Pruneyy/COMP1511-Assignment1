//A program to read and attempt to decipher a single digit in a captcha image
//Written 11 April 2017
//By Pranav Singh z3461857
//For COMP1511 Assignment 1

#include <stdio.h>
#include "captcha.h"

int main(int argc, char *argv[]) {

    int wide = 0;
    int width = 0;
    int lines = 0;
    int height = 0;
    int box_width = 0;
    int start_row = 0;
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
    double vert_hole = 0;
    double h_balance = 0;
    double v_balance = 0;
    double bottom_hole = 0;


    //This section is taken from the Lab07 test_print_image code - (assumed to be written by Andrew Taylor)
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return 1;
    }

    if (get_pbm_dimensions(argv[1], &height, &width) != 1) {
        return 1;
    }

    int pixels[height][width];
    if (read_pbm(argv[1], height, width, pixels)) {
        get_bounding_box(height, width, pixels, &start_row, &start_column, &box_height, &box_width);

        //From here is my own code
        hole = holes(height, width, pixels);

        //Using copy_pixels to define bounding box
        int box_pixels[box_height][box_width];
        copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, box_pixels);

        //Calling all the functions
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
            printf("8\n");
        }

        //For 1, 2, 3, 5, 7
        else if (hole == 0) {

            //Fake holes < 2
            if (fake_holes < 2 && lines > 2) {
                printf("2\n");
            } else if (fake_holes < 2 && lines == 2) {
                if (v_balance < 0.53) {
                    printf("2\n");
                } else {
                    printf("7\n");
                }
            } else if (fake_holes < 2 && lines < 2) {
                if (v_balance < 0.53) {
                    printf("1\n");
                } else {
                    printf("7\n");
                }
            }

            //Fake holes > 2
            else if (fake_holes > 2) {
                if (((h_balance > 0.5) || (v_balance > 0.5)) && (d_two > d_one)){
                    printf("3\n");
                } else {
                    printf("5\n");
                }
            }

            //Fake holes = 2
            else if (fake_holes == 2) {
                if (lines < 2) {
                    printf("1\n");
                } else if (lines > 2) {
                    if (h_balance > 0.5 && v_balance < 0.5 && (d_two > d_one)) {
                        printf("2\n");
                    } else if (((h_balance > 0.5) || (v_balance > 0.5)) && (d_two > d_one)){
                        printf("3\n");
                    } else {
                        printf("5\n");
                    }
                    
                } else if (lines == 2) {
                    if ((h_balance < 0.5) && (v_balance < 0.5) && (density < 0.5)) {
                        printf("1\n");
                    } else if (h_balance > 0.5 && v_balance < 0.5 && (d_two > d_one)) {
                        printf("2\n");
                    } else if (((h_balance > 0.5) || (v_balance > 0.5)) && (d_two > d_one)){
                        if (density > 0.4) {
                            printf("3\n");
                        }
                    } else {
                        printf("5\n");
                    }
                }
            }
            else {
                printf("3\n");
            }
        }

        //For 0, 4, 6, 9
        else if (hole == 1) {
            if (lines == 1) {
                if ((((h_balance > 0.5 && (wide >= 10)) || ((wide >= 10) && (v_balance < 0.5))) && (density < 0.5)) || (vert_hole > 0.5 && hor_hole < 0.5)) {
                    printf("4\n");
                } else {
                    printf("0\n");
                }             
            } else if ((((h_balance < 0.5) && (v_balance < 0.5)) && ((d_three > d_two) || (d_two < d_one && d_three && d_four))) || (vert_hole > 0.5 && hor_hole > 0.5)) {
                printf("6\n");
            } else if ((((h_balance > 0.5 && (wide >= 10)) || ((wide >= 10) && (v_balance < 0.5))) && (density < 0.5)) || (vert_hole > 0.5 && hor_hole < 0.5)) {
                printf("4\n");
            } else if ((v_balance > 0.5) || (d_three < (d_one && d_two && d_four)) || (vert_hole < 0.5 && hor_hole > 0.5)) {
                printf("9\n");
            } else {
                printf("0\n");
            }
        }
        
        else if (hole > 2) {
            printf("8\n");
        }

    }

    return 0;
}
