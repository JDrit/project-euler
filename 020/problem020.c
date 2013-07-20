#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

int main(int agrc, char *argv[]) {
    FILE *file = fopen("tmp.txt", "ab+");
    long sum = 0;
    int i;
    size_t sz;
    mpz_t number;

    mpz_init(number);
    mpz_fac_ui(number, 100);
    sz= mpz_sizeinbase(number, 10);
    mpz_out_str(file, 10, number);
    fclose(file);
    file = fopen("tmp.txt", "r");

    for (i = 0 ; i < sz - 1; i++) {
        char c = fgetc(file);
        printf("%c ", c);
        sum += c - '0';
    }
    fclose(file);
    remove("tmp.txt");

    printf("%ld\n", sum);
    
    return 0;
}
