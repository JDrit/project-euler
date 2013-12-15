#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int i, int j, short *perm) {
    int tmp = perm[i];
    perm[i] = perm[j];
    perm[j] = tmp;
}

void getNext(int N, short *perm) {
    int i = N - 1;

    while (perm[i - 1] >= perm[i]) {
        i--;
    }
    int j = N;
    while (perm[j - 1] <= perm[i - 1]) {
        j-=1;
    }

    swap(i - 1, j - 1, perm);

    i++;
    j = N;
    while (i < j) {
        swap(i - 1, j - 1, perm);
        i++;
        j--;
    }
}


int main (int argc, char *argv[]) {
    int N = 10; // value of n in nPr
    short *perm = malloc(N * sizeof(short));
    int i, j;

    for (j = 0 ; j < N ; j++) {
        perm[j] = j;
    }
    for (i = 1 ; i < 1000000 ; i++) {
        getNext(N, perm);
    }
    for (i = 0 ; i < N ; i++) {
        printf("%i", perm[i]);
    }
    printf("\n");
    free(perm);
    return 0;
}
