#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct bigBigInt {
    int digitCount;
    int byteSize;
    char *digitArr;
} bigInt;

char intToChar     (int digit);
int  charToInt     (char digit);
char shift         (char *arr);
bigInt getDig();

int main() {
    

    return 0;
}

