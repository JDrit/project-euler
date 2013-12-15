#include <stdio.h>
#include <stdlib.h>

void print_array(int r, int c, long **grid) {
    int i, j;
    for (i = 0 ; i < r ; i++) {
        for (j = 0 ; j < c ; j++) {
            printf("%03ld ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    long count = 1;
    int size = 1001; // change this only
    long **grid = malloc(size * sizeof(long *));
    long sum = 0;
    int i;
    int length = 1;
    int r = size / 2;
    int c = size / 2;
    int twice = 0;
    int direction = 1; // 0 = N, 1 = E, 2 = S, 3 = W
    int reverse = size;

    for (i = 0 ; i < size ; i++) {
        grid[i] = malloc(size * sizeof(long));
    }
    grid[r][c] = count++;

    while (count < size * size) {
        for(i = 1 ; i <= length ; i++) {
            switch(direction) {
                case 0:
                    grid[--r][c] = count++;
                    break;
                case 1:
                    grid[r][++c] = count++;
                    break;
                case 2:
                    grid[++r][c] = count++;
                    break;
                case 3:
                    grid[r][--c] = count++;
                    break;
            }
       }
        if (twice) {
            length++;
            twice = 0;
        } else {
            twice = 1;
        }
        direction = (direction == 3) ? 0 : direction + 1;
    }
    
    for (i = 0 ; i < size ; i++) {
        sum += grid[i][i];
        sum += grid[i][--reverse];
    }
    sum--;
    printf("%ld\n", sum);
    return 0;
}
