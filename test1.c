#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct digities {
    int firstD;
    int seconD;
    int countD;
    double fubble;
} bigInt;

int check = 1;

int main() {
    bigInt fibo;
    bigInt *fiboPP = &fibo;

    int i = 5;

    fibo.firstD = 1;
    fibo.countD = 5;
    fibo.fubble = 555555;

    // printf("%lu\n", sizeof(fibo));
    // printf("%lu\n", sizeof(fiboPP));

    // printf("%d\n", (*fiboPP).countD);

    printf("111\v\b111\n");
    printf("222222\n");
    printf("333333");
    printf("\r");
    printf("\n");
    printf("%d\n", fibo);


    // printf("\b\b\b\b\b");
    // printf("3\r");
    // printf("\b");

    return 0;
}