#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct digities {
    int firstD;
    int seconD;
    int countD;
} bigInt;

int check = 1;

int selfCountingFiboRecurse(bigInt A);

int main() {
    bigInt fibo;
    fibo.firstD = 1;
    fibo.countD = 0;
    selfCountingFiboRecurse(fibo);

    return 0;
}

int selfCountingFiboRecurse(bigInt fibo) {
    if (fibo.countD == 12) {
        return 0;
    }
    if (check == 1) {
        check = 0;
        fibo.seconD += fibo.firstD;
        fibo.countD++;
        printf("%d %d\n", fibo.countD, fibo.seconD);
    } else if (check == 0) {
        check = 1;
        fibo.firstD += fibo.seconD;
        fibo.countD++;
        printf("%d %d\n", fibo.countD, fibo.firstD);
    }
    selfCountingFiboRecurse(fibo);
    return 0;
}