#include <stdio.h>

int main(int argc, char *argv[]) {
    int count = 20;

    while(1) {
        if (count % 19 == 0 &&
                count % 18 == 0 &&
                count % 17 == 0 &&
                count % 16 == 0 &&
                count % 15 == 0 &&
                count % 14 == 0 &&
                count % 13 == 0 &&
                count % 12 == 0 &&
                count % 11 == 0) {
            printf("goal:%i\n", count);
            break;
        } else {
            count += 20;
        }
    }
    return 0;
}
