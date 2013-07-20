#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int size = 10000;
    long *sums = malloc(size * sizeof(long));
    long sum = 0;
    int i, j;

    /* makes the list of the divsors sums */
    for (i = 1 ; i < size ; i++) {
        for (j = i ; j < size ; j++) {
            if (j % i == 0 && j != i) {
                sums[j] += i;
            }          
        }
    }

    for (i = 1 ; i < size ; i++) {
        if (sums[i] < size && i == sums[sums[i]] && i != sums[i]) {
            sum += i;
        }
    }

    printf("%ld\n", sum);
    free(sums);

    return 0;
}
