#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int best = 0;
    long start;
    long i;
    clock_t begin = clock(), end;
    for (i = 2 ; i < 1000000 ; i++) {
        long tmp = i;
        int count = 0;
        while (tmp != 1) {
            tmp = (tmp % 2 == 0) ? tmp / 2 : tmp * 3 + 1;
            count++;
        }
        if (count > best) {
            best = count;
            start = i;
        }
    }
    end = clock();
    printf("%i\ntime:%d\n", start, (double) (end - begin) / CLOCKS_PER_SEC);
    return 0;
}
