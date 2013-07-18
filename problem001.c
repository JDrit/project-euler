#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]) - 1;
    int threes  = 3 * (((n / 3) * ((n / 3) + 1)) / 2 );
    int fives = 5 * (((n / 5) * ((n / 5) + 1)) / 2);
    int fifteens = 15 * (((n / 15) * ((n / 15) + 1)) / 2);
    printf("%i %i %i\n", threes, fives, fifteens);
    printf("%i\n", threes + fives - fifteens);

    return 0;
}
