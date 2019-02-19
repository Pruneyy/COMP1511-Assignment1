





        int pixels[height][width];
        if (read_pbm(argv[1], height, width, pixels)) {

            for (w = 0; w < width; w+=50) {
                copy_pixels(height, width, pixels, start_row, w, height, 50, smaller_pixels);


                get_bounding_box(height, width, smaller_pixels, &start_row, &start_column, &box_height, &box_width);

                hole = holes(height, width, smaller_pixels);

                int box_pixels[box_height][box_width];
                copy_pixels(height, width, smaller_pixels, start_row, start_column, box_height, box_width, box_pixels);

                hole = holes(height, width, smaller_pixels);

                h_balance = get_horizontal_balance(box_height, box_width, box_pixels);

                v_balance = get_vertical_balance(box_height, box_width, box_pixels);

                density = get_density(box_height, box_width, box_pixels);

                get_quadrant_density(box_height, box_width, box_pixels, &d_one, &d_two, &d_three, &d_four, &wide);

                lines = get_lines(box_height, box_width, box_pixels);

                vert_hole = get_vert_hole_balance(box_height, box_width, box_pixels);

                hor_hole = get_hor_hole_balance(box_height, box_width, box_pixels);

                //Check for single digit here



