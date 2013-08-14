#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *atkinSieve(int limit, int *count) {
    int *results = malloc(limit * sizeof(int));
    results[0] = 2;
    results[1] = 3;
    results[2] = 5;
    *count = 3;
    int *sieve = malloc((limit + 1) * sizeof(int));
    double factor = sqrt(limit) + 1;
    int i, j;
    for (i = 1 ; i < factor ; i++) {
        for (j = 1 ; j < factor ; j++) {
            int n = 4 * pow(i, 2) + pow(j, 2);
            if (n <= limit && (n % 12  == 1 || n % 12 == 5)) {
                sieve[n] = sieve[n] == 0 ? 1 : 0;
            }
            n = 3 * pow(i, 2) + pow(j, 2);
            if (n <= limit && n % 12 == 7) {
                sieve[n] = sieve[n] == 0 ? 1 : 0;
            }
            if (i > j) {
                n = 3 * pow(i, 2) - pow(j, 2);
                if (n <= limit && n % 12  == 11) {
                    sieve[n] = sieve[n] == 0 ? 1 : 0;
                }
            }


        }
    }
    for (i = 5 ; i < factor ; i++) {
        if (sieve[i]) {
            for (j = pow(i, 2) ; j < limit ; j += pow(i, 2)) {
                sieve[j] = 0;
            }
        }
    }
    for (i = 7 ; i < limit ; i++) {
        if (sieve[i]) {
            results[(*count)++] = i;
        }
    }
    free(sieve);
    return results;

}

int main(int argc, char *agrv[]) {
    int count;
    int *primes = atkinSieve(1000000, &count);
    int i;
    int length = 0;
    int best = 0; 
    for (i = 0 ; i < count ; i++) {
        int start = 0;
        while (start++ != i) {
            int sum = 0;
            int j = start;
            int tempLength = 0;
            while (sum < primes[i]) {
                tempLength++;
                sum += primes[j++];
            }
            if (sum == primes[i] && tempLength > length && sum > best) {
                length = tempLength;
                best = sum;
            }
        }
    }
    printf("length: %i\n", length);
    printf("number: %i\n", best);
    free(primes);
    return 0;
}
