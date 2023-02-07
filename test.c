#include <stdio.h>
#include <stdlib.h>

char* concatFunc(char *arr1, char *arr2);

int main() {
    char arr1[] = "Bill_";
    char arr2[] = "Murray";

    printf("%lu\n", sizeof(arr1));

    char *arrConcat = concatFunc(arr1, arr2);
    printf("%s\n", arrConcat);

    return 0;
}

char* concatFunc(char *arr1, char *arr2) {
    int concatSize = sizeof(arr1) + sizeof(arr2) + 1;

    char *arrConcat = (char*)calloc(concatSize, sizeof(char));

    for (int i = 0; i < sizeof(arr1); i++) {
        arrConcat[i] = arr1[i];
    }

    printf("%lu\n", sizeof(arr1));
    printf("%lu\n", sizeof(concatSize));

    int y = 0;
    for (int i = sizeof(arr1) - 3; i < concatSize; i++) {
        arrConcat[i] = arr2[y++];
    }

    return arrConcat;
}