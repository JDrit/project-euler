#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *getBase2(int n) {
    int converted[20];
    int index = 0;
    while (n != 0) {
        converted[index++] = n % 2;
        n = n / 2;
    }
    char *str = malloc((index + 1)* sizeof(char));
    int i = 0;
    for ( ; index > 0 ; index-- ) {
        str[i++] = (char) (((int) '0') + converted[index - 1]);
    }
    str[i] = '\0';
    return str;
}

void reverse(char *s) {
    char *end;
    for (end = s + strlen(s) - 1 ; end > s; --end, ++s) {
        (*s) ^= (*end);
        (*end) ^= (*s);
        (*s) ^= (*end);
    }
}

int main(int argc, char *argv[]) {
    long sum = 0;
    long i;

    for (i = 1 ; i < 1000000 ; i++) {
        char *baseStr = getBase2(i);
        char *baseRev = strdup(baseStr);
        char *numStr = malloc(7 * sizeof(char));
        sprintf(numStr, "%ld", i);
        char *numRev = strdup(numStr);

        reverse(baseRev);
        reverse(numRev);
        
        if (!strcmp(baseStr, baseRev) && !strcmp(numStr, numRev)) {
            sum += i;
        }

        free(baseStr);
        free(baseRev);
        free(numStr);
        free(numRev);
    }
    printf("sum: %ld\n", sum);
    return 0;
}
