#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char reverseString(char *arr);

int main() {
    int H = 3;
    int W = 20;

    char **A = (char **)calloc(H, sizeof(char *));

    for(int i=0; i<H; i++) {
        A[i] = (char *)calloc(W, sizeof(char));
    }

    char c;
    int i = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            break;
        }
        A[0][i++] = c;
    }

    reverseString(*A);

    printf("%s\n", *A);

    return 0;
}

char reverseString(char *arr) {
    int temp;
    int lenght = strlen(arr)-1;
    printf("%d\n", lenght);
    for(int i = 0; i < lenght/2; i++) {
        temp = arr[i];
        arr[i] = arr[lenght];
        arr[lenght--] = temp;
    }
    return *arr;
}