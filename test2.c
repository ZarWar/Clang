#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 4

int main() {
    int H = 2;
    int W = 1;

    char **twodArr = (char **)calloc(H, sizeof(char *));
    for(int i=0; i<H; i++) {
        twodArr[i] = (char *)calloc(W, sizeof(char));
    }

    // twodArr[0][0] = '1';

    // char *temp = &twodArr;
    // twodArr[1][0] = '2';

    for(int i=0; i<5; i++) {
        twodArr[i] = realloc(twodArr[i], 1);
    }

    // twodArr = &temp;
    twodArr[4][0] = '2';

    printf("%c\n", twodArr[4][0]);
}