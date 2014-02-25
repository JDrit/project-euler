#include <stdio.h>
#include <stdlib.h>

int main(int agtc, char *argv[]) {
    int amount = 100;
    int size = 50;
    int numbers[amount][size];
    int answer[size];
    FILE *file;
    int i, j, carryOver = 0;


    file = fopen("numbers.txt", "r");
    for (i = 0 ; i < amount ; i++) {
        for (j = 0 ; j < size ; j++) {
            char c = (char) fgetc(file);
            if (c != '\n') {
                numbers[i][j] = c - '0';
            } else {
                numbers[i][j] = (char) fgetc(file) - '0';
            }
        }
    }
    fclose(file);
    
    for (i = size - 1; i >= 0 ; i--) {
        int sum = carryOver;
        for (j = 0 ; j < amount ; j++) {
            sum += numbers[j][i];
        }
        answer[i] = sum % 10;
        carryOver = sum / 10;

    }
    printf("%i", carryOver); // the end carry over
    for (i = 0 ; i < size ; i++) {
        printf("%i", answer[i]);
    }
    printf("\n");
    return 0;
}
