        //For 8
        if (hole == 2) {
            printf("8\n");
        }
        //For 1, 2, 3, 5, 7
        else if (hole == 0) {
            if (lines == 3) {
                if (h_balance > 0.5 && v_balance < 0.5 && (d_two > d_one)) {
                    printf("2\n");
                } else if (((h_balance > 0.5) || (v_balance > 0.5)) && (d_two > d_one)){
                    if (density > 0.4) {
                        printf("3\n");
                    }
                } else {
                    printf("5\n");
                }
            }
            else if ((h_balance < 0.5) && (v_balance < 0.5) && (density < 0.5)) {
                //if (wide > 5) {
                    printf("1\n");
                //}
            } else if (h_balance > 0.5 && v_balance < 0.5 && (d_two > d_one)) {
                printf("2\n");
            } else if (((h_balance > 0.5) || (v_balance > 0.5)) && (d_two > d_one)){
                if (density > 0.4) {
                    printf("3\n");
                } else if (density < 0.4) {
                    printf("7\n");
            } 
            } else {
                printf("5\n");
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

    }
    return 0;
}
