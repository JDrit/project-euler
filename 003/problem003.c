#include <stdio.h>
#include <math.h>

int isPrime(long number) {
    long i;
    for (i = 2 ; i < sqrt(number) ; i++) {
        if (number % i == 0 && i != number) {
            return 0;
        }
    }
    return 1;
}
int main(int argc, char *argv[]) {
    long num = 600851475143;
    long i;
    for (i = sqrt(num) ; i > 0 ; i--) {
        if (isPrime(i) && num % i  == 0) {
            printf("goal: %lu\n", i);
            break;
        }
    }
    return 0;
}
