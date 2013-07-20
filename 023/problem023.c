#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i, j;
    int count = -1;
    long sum = 0;
    int size = 23123;
    long *abundents = malloc(size * sizeof(long));
    long *divisors = malloc(size * sizeof(long));
    short *bad = malloc((size) * sizeof(int));
    
    /* gets the sum of the divisors of all numbers */
    for (i = 1 ; i < size ; i++) {
         for (j = i ; j < size ; j++) {
            if (j % i == 0 && j != i) {
                divisors[j] += i;
            }
         }
    }
    
    /* gets the list of all the abundent numbers */
    for (i = 2 ; i < size ; i++) {
        if (divisors[i] > i) {
            abundents[++count] = i;
        }
    }

    for (i = 0 ; i < count ; i++) {
        for (j = i ; j < count ; j++) {
            if (abundents[i] + abundents[j] <= size) {
                bad[abundents[i] + abundents[j]] = 1;
            } else {
                break;
            } 
        }
    }
    for (i = 1 ; i <= size ; i++) {
        if (!bad[i]) {
            sum += i;
        }
    }
    printf("%ld\n", sum);

    free(abundents);
    free(divisors);
    free(bad);
    return 0;
}
