#include <stdio.h>

int raiseTo(int number, int raise) {
    int result = 1;
    while (raise-- > 0) {
        result *= number;
    }
    return result;
}

int main(int argc, char *argv[]) {
    int sol = (raiseTo(100, 4) + 2 * raiseTo(100, 3) + raiseTo(100, 2)) / 4 - (100 * (100 + 1) * (2 * 100 + 1)) / 6;
    printf("%i\n", sol);
    return 0;
}
