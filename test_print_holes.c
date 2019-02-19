#include <stdio.h>
#include "captcha.h"

int main(int argc, char *argv[]) {
    int height, width;
    int fake_holes = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return 1;
    }

    // first get image dimensions
    if (get_pbm_dimensions(argv[1], &height, &width) != 1) {
        return 1;
    }

    // now declare appropriate array
    int pixels[height][width];
    if (read_pbm(argv[1], height, width, pixels)) {
        get_bounding_box(height, width, pixels, &start_row, &start_column, &box_height, &box_width);

        int box_pixels[box_height][box_width];
        copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, box_pixels);

        fake_holes = get_horizontal_balance(box_height, box_width, box_pixels);

        printf("Horizontal balance %d\n", fake_holes);
    }
    return 0;
}
