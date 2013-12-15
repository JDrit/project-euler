#include <stdio.h>

int main(int argc, char *argv[]) {
    int primes[10001] = {0};
    int count = 0;
    int current = 2;

    while (count < 10001) {
        int i = 0;
        int new = 1;
        while (primes[i] != 0) {
            if (current % primes[i] == 0) {
                new = 0;
                break;
            }
            i++;
        }
        if (new) {
            primes[i] = current;
            count++;
        }
        current++;
    }
    printf("%i\n", --current);
    return 0;
}
