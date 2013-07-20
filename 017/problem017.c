#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char * str) {
    if (str) {
        char * end = str + strlen(str) - 1;

        // swap the values in the two given variables
        // XXX: fails when a and b refer to same memory location
    #   define XOR_SWAP(a,b) do\
        {\
            a ^= b;\
            b ^= a;\
            a ^= b;\
        } while (0)

        // walk inwards from both ends of the string, 
        // swapping until we get to the middle
        while (str < end) {
            XOR_SWAP(*str, *end);
            str++;
            end--;
        }
    #   undef XOR_SWAP
    }
}

int main(int argc, char *argv[]) {
    int sum = 0;
    char *number;
    int i;
    int place;

    for (i = 100 ; i < 1000 ; i++) {
        if (i < 10) {
            number = malloc(2 * sizeof(char));
        } else if (i < 100) {
            number = malloc(3 * sizeof(char));
        } else if (i < 1000) {
            number = malloc(4 * sizeof(char));
        } else {
            number = malloc(5 * sizeof(char));
        }
        sprintf(number, "%d", i);
        place = 1;
        if (strcmp(number, "11") == 0 || strcmp(number, "12") == 0) {
            sum += 6;
        } else if (strcmp(number, "13") == 0|| strcmp(number, "14") == 0|| 
                   strcmp(number, "18") == 0|| strcmp(number, "19") == 0) {
            sum += 8;
        } else if (strcmp(number, "15") == 0|| strcmp(number, "16") == 0) {
            sum += 7;
        } else if (strcmp(number, "17") == 0) {
            sum += 9;
        } else if (strcmp(number, "10") == 0) {
                sum += 3;
        } else if (strcmp(number, "1000") == 0) {  
            sum += 3 + 8;
        } else {
            reverse(number);
            do {
                switch (*number) {
                    case '1':
                        if (place == 1) {
                            sum += 3;
                        } else if (place == 3) {
                            sum += 13;
                        }
                        break;
                    case '2':
                        if (place == 1) {
                            sum += 3;
                        } else if (place == 2) {
                            sum += 6;
                        } else if (place == 3) {
                            sum += 13;
                        }
                        break;
                    case '3':
                        if (place == 1) {
                            sum += 5;
                        } else if (place == 2) {
                            sum += 6;
                        } else if (place == 3) {
                            sum += 15;
                        }
                        break;
                    case '4':
                        if (place == 1) {
                            sum += 4;
                        } else if (place == 2) {
                            sum += 5;
                        } else if (place == 3) {
                            sum += 14;
                        }
                        break;
                    case '5':
                        if (place == 1) {
                            sum += 4;
                        } else if (place == 2) {
                            sum += 5;
                        } else if (place == 3) {
                            sum += 14;
                        }
                        break;
                    case '6':
                        if (place == 1) {
                            sum += 3;
                        } else if (place == 2) {
                            sum += 5;
                        } else if (place == 3) {
                            sum += 13;
                        }
                        break;
                    case '7':
                        if (place == 1) {
                            sum += 5;
                        } else if (place == 2) {
                            sum += 7;
                        } else if (place == 3) {
                            sum += 15;
                        }
                        break;
                    case '8':
                        if (place == 1) {
                            sum += 5;
                        } else if (place == 2) {
                            sum += 6;
                        } else if (place == 3) {
                            sum += 15;
                        }
                        break;
                    case '9':
                        if (place == 1) {
                            sum += 4;
                        } else if (place == 2) {
                            sum += 6;
                        } else if (place == 3) {
                            sum += 14;
                        }
                        break;
                    default:
                        break;
                }
                place++;
            } while (*number++ != '\0');
        }
        printf("%i %i \n", i, sum);
    }
//    sum -= 30;
    printf("sum: %i\n", sum);
    return 0;
}
