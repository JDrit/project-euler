#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int isPrime(long number) {
    long i;
    for (i = 2 ; i <= sqrt(number) ; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}


int main(int argc, char *argv[]) {
    long i;
    int length;
    int count = 0;
    char *number = malloc(8 * sizeof(char));
    char *version = malloc(8 * sizeof(char));
    char tmp;
    int size;
    int bad = 0;

    for (i = 2 ; i < 1000000 ; i++) {
        sprintf(number, "%ld", i);
        size = 0;
        bad = 0;
        while (size++ <= strlen(number)) {
            tmp = *number;
            for (length = 0 ; length < strlen(number) - 1; length++) {
                number[length] = number[length + 1];
            }
            if (strlen(number) > 1) {
                number[length] = tmp;
            }
            if (!isPrime(atol(number))) {
                bad = 1;
                break;
            }
        }
        
        if (!bad) {
            printf("%ld\n", i);
            count++;
        }
    }
    printf("%i\n", count);
    return 0;

}
