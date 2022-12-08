#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct digities {
    int firstD;
    int seconD;
    int countD;
} nameIt;

int check = 1;

int selfCountingFiboRecurse(nameIt A);

int main() {
    nameIt fibo;
    fibo.firstD = 1;
    fibo.countD = 1;
    selfCountingFiboRecurse(fibo);

    return 0;
}

int selfCountingFiboRecurse(nameIt fibo) {
    if (fibo.countD == 10) {
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
}