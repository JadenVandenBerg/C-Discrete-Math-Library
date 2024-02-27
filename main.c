#include <stdio.h>
#include "library.h"

int main() {
    printf("In Main");

    int len = 5;
    int * arr = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        arr[i] = i;
    }

    PM_permutation * parent = PM_newPermutation(len, arr, 0);

    int leng;
    PM_permutation ** subs = PM_findSubPermutations(parent, &leng);
    printf("%d", leng);

    for (int i = 0; i < leng; i++) {
        PM_printPermutation(subs[i]);
    }

    return 0;
}