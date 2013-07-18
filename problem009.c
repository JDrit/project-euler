#include <stdio.h>

int main(int argc, char *argv[]) {
    int a, b, c;

    for (a = 0 ; a < 9998 ; a++) {
        for (b = a + 1 ; b < 9998 ; b++) {
            for (c = b + 1 ; c < 998 ; c++) {
                if (a + b + c == 1000 && a * a + b * b == c * c) {
                    printf("%i\n", a * b * c);
                    return 0;
                }
            }
        }
    }

    return 0;
}
