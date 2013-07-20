#include <stdio.h>
#include <stdlib.h>

void routePick(int r, int c, int row_max, int col_max, long tri[row_max][col_max]) {
    if (r == 0 && c == 0) {
        routePick(1, 0, row_max, col_max, tri);
    } else if (r < row_max) {
        if (c > 0 && tri[r - 1][c] != 0) { // inside piece
            tri[r][c] += tri[r - 1][c] > tri[r - 1][c - 1] ? tri[r - 1][c] : tri[r - 1][c - 1];
            routePick(r, c + 1, row_max, col_max, tri);
        } else if (c > 0) { // right
            tri[r][c] += tri[r - 1][c -1];
            routePick(r + 1, 0, row_max, col_max, tri);
        } else { // left side
            tri[r][c] += tri[r - 1][c];
            routePick(r, c + 1, row_max, col_max, tri);
        }
        
    }

}

void printArray(int r, int c, long memo[r][c]) {
    int i, j;
    for (i = 0 ; i < r ; i++) {
        for (j = 0 ; j < c ; j++) {
            printf("%ld ", memo[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    FILE *file = fopen("triangle.txt", "r");
    long tri[100][100] = { {0} };
    long memo[100][100] = { {0} };
    int best = 0;
    int result;
    int i, j;
    for (i = 0 ; i < 100 ; i++) {
        for (j = 0 ; j <= i ; j++) {
            fscanf(file, "%d", &tri[i][j]);
        }
    }
    routePick(0, 0, 100, 100, tri);
    for (i = 0 ; i < 100 ; i++) {
        if (best < tri[99][i]) {
            best = tri[99][i];
        }
    }
    printf("best: %i\n", best);
    return 0;
}
