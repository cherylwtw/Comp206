/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<stdio.h>


void PrintRow(int row, int height,int level) {
    if (level == 1) {
        int row_item_count = 2*height-1;
        char array[row_item_count+1];
        int star_count = 2*row+1;
        int space_around_count = (row_item_count - star_count)/2;
            
        for (int i =0; i< row_item_count; i++) {
            if (i<space_around_count) {
                array[i] = '-';
            }
            else if ( i > row_item_count-space_around_count-1) {
                array[i] = '-';
            }
            else
                array[i] = '*';
        }
        array[row_item_count] = '\0';
        printf("%s", array);
        return;
    }
    else if (row < height/2) {
        char space_arrary[height/2+1];
        for (int i = 0; i< height/2; i++) {
            space_arrary[i] = '-';
        }
        space_arrary[height/2] = '\0';
        printf("%s", space_arrary);
        PrintRow(row, height/2, level-1);
        printf("%s", space_arrary);
    }
    else {
        PrintRow(row-height/2, height/2, level-1);
        printf("-");
        PrintRow(row-height/2, height/2, level-1);
    }
    return;
}

void DrawSierpinskiTriangle(int height, int level) {
    for (int row=0; row<height; row++) {
        PrintRow(row, height, level);
        printf("\n");
    }
}


int main (int argc, char** argv) {
    const int test_count = 4;
    int triangle_test[test_count][2] = {{30, 1}, {14, 2}, {16, 3}, {16, 4}};

    for (int i = 0; i < test_count; i++ ) {
        int height = triangle_test[i][0];
        int level = triangle_test[i][1];
        printf("print triangle with height = %d, level = %d\n", height, level);
        DrawSierpinskiTriangle(triangle_test[i][0], triangle_test[i][1]);
        printf("###################################\n");
    }
}