//Header file containing functions for use in assignment
//Written 12 April 2017
//By Pranav Singh z3461857 (Part of this file is from Lab07 - lab partner Matthew Chhoeu)
//For COMP1511 Assignment 1


//read_pbm and get_pbm_dimensions is from Andrew Taylor
int read_pbm(char filename[], int height, int width, int pixels[height][width]);
int get_pbm_dimensions(char filename[], int *height, int *width);

//This section is from Lab07 (Lab partner Matthew Chhoeu)
void print_image(int height, int width, int pixels[height][width]);
void get_bounding_box(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width);
void copy_pixels(int height, int width, int pixels[height][width],
                 int start_row, int start_column, int copy_height, int copy_width,
                 int copy[copy_height][copy_width]);
double get_horizontal_balance(int height, int width, int pixels[height][width]);

//This section is my own individual work
double holes(int height, int width, int pixels[height][width]);
void print_holes(int height, int width, int pixels[height][width]);
double get_vertical_balance(int height, int width, int pixels[height][width]);
double get_density(int height, int width, int pixels[height][width]);
void get_quadrant_density(int height, int width, int pixels[height][width], double *density_one, double *density_two, double *density_three, double *density_four, int *wide);
int get_lines(int height, int width, int pixels[height][width]);
double get_vert_hole_balance(int height, int width, int pixels[height][width]);
double get_hor_hole_balance(int height, int width, int pixels[height][width]);
double fake_hole(int height, int width, int pixels[height][width]);
void hole_fraction(int height, int width, int pixels[height][width], double *top_hole_fraction, double *bottom_hole_fraction);


