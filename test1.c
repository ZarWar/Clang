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

    fibo.firstD = 1;
    fibo.countD = 5;
    fibo.fubble = 555555;

    printf("%lu\n", sizeof(fibo));
    printf("%lu\n", sizeof(fiboPP));

    printf("%d\n", (*fiboPP).countD);

    return 0;
}