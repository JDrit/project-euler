#include <stdio.h>

int main(int argc, char *argv[]) {
    int singles = 36;
    int teens = 70;

    int doubleDigits = 10 * 46 + 8 * singles;

    int threeDigits = singles * 100 + 9 * (singles + teens + doubleDigits) + 7 * 9 + 9 * 99 * 10;
    printf("%i\n", singles + teens + doubleDigits + threeDigits + 11);
    
}
