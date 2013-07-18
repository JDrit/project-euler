#include <stdio.h>

int main(int agrc, char *argv[]) {
    long sum = 0l;
    int primes[1000000] = {0};
    int i;

    for (i = 2 ; i < 2000000 ; i++) {
        int j = 0;
        int new = 1;
        while (primes[j] != 0) {
            if (i % primes[j] == 0) {
                new = 0;
                break;
            }
            j++;
        }
        if (new) {
            primes[j] = i;
            sum += i;
            printf("%i %ld\n", i, sum);
        }
    }
    printf("%ld\n", sum);
    return 0;
    
}
