#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gmp.h>

int cmp(const void *a, const void *b) {
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return -strcasecmp(*ib, *ia);
}

int main(int argc, char *argv[]) {
    FILE *file = fopen("names.txt", "r");
    char line[12];
    int size = 5163;
    char **names = malloc(size * sizeof(char*));
    int count = 0;
    int i;
    char c;
    mpz_t number;

    if (file == NULL) {
        exit(EXIT_FAILURE);
    }

    mpz_init(number);    
    
    for (i = 0 ; i < size ; i++) {
        fscanf(file, "%s", line);
        names[i] = strdup(line);
    }

    /* sorts the list of names alphabetically */
    qsort(names, size, sizeof(char *), cmp);

    for (i = 0 ; i < size ; i++) {
        c = *names[i]++;   
        int count = 0;
        do {
            count += c - 'A' + 1;
            c = *names[i]++;   
        } while (c != '\0');
        mpz_add_ui(number, number, (i + 1) * count);
    }
    mpz_out_str(stdout, 10, number);
    printf("\n");
    return 0;
}
