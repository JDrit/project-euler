#include <stdio.h>

int main(int argc, char *argv[]) {
    long last = 0;
    long current = 1;
    long sum = 0;
    while (current <= 4000000) {
        if (current % 2 == 0) {
            sum += current;
        }
        long temp = current;
        current += last;
        last = temp;
    }
    printf("sum: %lu\n", sum);
    return 0;
}
