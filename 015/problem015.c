#include <stdio.h>

long pathCount(int r, int c, int row_max, int col_max, long memo[row_max + 1][col_max + 1]) {
    long count = 0;
        if (r < row_max) {
            if (memo[r + 1][c]) {
                count += memo[r + 1][c];     
            } else {
                count += pathCount(r + 1, c, row_max, col_max, memo);
            }
        }
        if (c < col_max) {
            if (memo[r][c+1]) {
                count += memo[r][c + 1];
            } else {
                count += pathCount(r, c + 1, row_max, col_max, memo);
            }
        }
        memo[r][c] = count;
        if (r == row_max && c == col_max) {
            count++;
            memo[r][c] == 1;
        }
        return count;
}


int main(int argc, char *argv[]) {

    long memo[21][21] = { {0} };
    printf("%ld\n", pathCount(0, 0, 20, 20, memo));
    return 0;
}
