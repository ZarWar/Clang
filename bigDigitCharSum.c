#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Вся эта хуеборина работает почти норм, но последний остаток от суммы не умеет переносить на 1+ регистр.
То-есть 550+550=(1)100. единица в скобках остаётся "за кадром" */

char intToChar (int digit);
int  charToInt (char digit);

int ostatok = 0;

int main() {
    int H = 3;
    int W = 4;
    int n = 0;
    int big;
    int smaller;
    int temp1Reg;
    int temp2Reg;
    int tempDigit;

    char **A = (char **)calloc(H, sizeof(char *));

    for(int i = 0; i < H; i++) {
        A[i] = (char *)calloc(W, sizeof(char));
    }

    char c;
    int i = 0;
    int y = 0;
    while((c = getchar()) != EOF) {
        if(i == W - 1) {
            W *= 2;
            A[y] = (char *)realloc(A[y], W * sizeof(char));
        }
        
        if(c == '\n') {
            n++;
            if (n == 2) {
                break;
            }
            y++;
            i = 0;
        } else {
            A[y][i++] = c;
        }
    }

    printf("\n");
    printf("A[0] = '%s'\n", A[0]);
    printf("A[1] = '%s'\n", A[1]);

    if(strlen(A[y]) > strlen(A[y-1])) {
        big = strlen(A[y]);
        smaller = strlen(A[y-1])-1;
    } else {
        big = strlen(A[y-1]);
        smaller = strlen(A[y])-1;
    }
     
    printf("big     = '%d'\n", big);
    printf("smaller = '%d'\n", smaller);
    printf("\n");

    for(int i = big - 1; i >= 0; i--) {
        
        if(ostatok != 0) {
            tempDigit = charToInt(A[0][i]) + charToInt(A[1][smaller--]) + ostatok;
        }
        if (ostatok == 0) {
            tempDigit = charToInt(A[0][i]) + charToInt(A[1][smaller--]);
        }

        if(tempDigit > 9) {
            printf("str 73\n");
            temp2Reg = tempDigit / 10;
            temp1Reg = tempDigit % 10;
        } else {
            printf("str 77\n");
            temp1Reg = tempDigit;
            temp2Reg = 0;
        }

        if (temp2Reg > 0) {
            printf("str 83\n");
            ostatok = temp2Reg;
        } else {
            printf("str 86\n");
            ostatok = 0;
        }

        A[2][i] = intToChar(temp1Reg);
    }
    printf("summa = %s\n", A[2]);

    return 0;
}

char intToChar (int digit) {
    if(digit >= 0 && digit <= 9) {
        return digit + 48;        
    }
    return 0;
}

int charToInt (char digit) {
    if(digit >= '0' && digit <= '9') {
        return digit - 48;        
    }
    return 0;
}