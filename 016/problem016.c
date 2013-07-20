#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    mpz_t base, result;
    int i;
    int sum = 0;

    mpz_init(base);
    mpz_init(result);
    mpz_set_ui(result, 0);
    mpz_set_ui(base, 2);
    
    mpz_pow_ui(result, base, 1000);
    size_t sz = mpz_sizeinbase(result, 10);
    FILE *file = fopen("tmp.txt", "ab+");
    mpz_out_str(file, 10, result);
    fclose(file);
    file = fopen("tmp.txt", "r");

    for (i = 0 ; i  < sz ; i++) {
        sum += fgetc(file) - '0';
    }
    fclose(file);
    remove("tmp.txt");
    printf("%i\n", sum);
    return 0;
}
