#include <stdio.h>
#include <gmp.h>

int main (int argc, char *argv[]) {
    mpz_t current, minus1, minus2;
    mpz_init(current);
    mpz_init(minus1);
    mpz_init(minus2);
    mpz_set_ui(current, 8);
    mpz_set_ui(minus1, 5);
    mpz_set_ui(minus2, 3);
    long long count = 6;
    
    while (mpz_sizeinbase(current, 10) < 1000) {
        mpz_add(current, minus1, minus2);
        mpz_set(minus2, minus1);
        mpz_set(minus1, current);
        count++;
    }
    printf("%lld\n", count);
    return 0;
}
