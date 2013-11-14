#include <stdio.h>
#include "hashset.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *foo = malloc(sizeof(int));
    int *missing  = malloc(sizeof(int));
    hashset_t set = hashset_create();
    *foo = 5;
    hashset_add(set, foo);
    *foo = 9;
    printf("%i\n", hashset_is_member(set, foo));

    printf("%i\n", hashset_is_member(set, missing));
}
