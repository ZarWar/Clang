#include <stdio.h>
#include <stdlib.h>

void printTree (int digit, int howDeep);
int  power     (int digit, int base);

int main() {
    int howDeep = 4;


    // int digitCount = 1;
    // for(int i = 1; i <= howDeep; i++) {
    //     printf("_");
    //     if(i == howDeep && digitCount != 0) {
    //         printf("%d", howDeep);
    //         i = 0;
    //         digitCount--;
    //     }
    // }
    // printf("\n");


    int digit = power(2, 3);

    printTree(digit, howDeep);

    return 0;
}

void printTree(int digit, int howDeep) {
    int deepCount = howDeep; // эта переменная является отсечкой для принта "_"
    int deepCountControl = howDeep; // эта переменная статична, нужна для сравнения с декрементируемой howDeep
    int digitCount = 1; // эта переменная декрементируется
    int digitCountControl = 1; // эта переменная растёт вверх в логарифмической прогрессии

    for(int i = 1; i <= howDeep; i++) {
        if(digitCount == howDeep) {
            for(int y = 1; y <= (2 * deepCount) - 1; y++) {
                printf("_");
                if(y == (2 * deepCount) - 1 && digitCount != 0) {
                    printf("%d", digit);
                    y = 0;
                    digitCount--;
                }
            }
            deepCount--;
            digitCountControl *= 2;
            digitCount = digitCountControl;
            printf("\n");
        } else if (digitCount != howDeep && digitCount != 1) {
            for(int y = 1; y <= (2 * deepCount) - 1; y++) {
                printf("_");
                if(y == (2 * deepCount) - 1 && digitCount != 0) {
                    printf("%d", digit);
                    y = 0;
                    digitCount--;
                }
            }
            deepCount--;
            digitCountControl *= 2;
            digitCount = digitCountControl;
            printf("\n");
        } esle if (digitCount == 1) {
            
        }

    }

}

int power(int digit, int base) {
    int temp = digit;
    for(int i = 1; i < base; i++) {
        temp *= digit;
    }

    return temp;
}