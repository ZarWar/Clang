#include <stdio.h>

void intToCharString(int n, char from[], char to[]);
int  intToString(int n, int from[], int to[]);
char reverseString(char from[], char to[], int size);
char convertIntToNumericBase(int digit, char string, int base);
int  power(int digit, int base);
void convertCharToInt(char from[], int to[]);
char decToHex(int digit[], char to[]);

int size = 0;

int main() {
    int n = 168;
    char from[10] = {0};
    char to[10] = {0};
    int digit[10] = {0};
    intToCharString(n, from, to);
    convertCharToInt(from, digit);
    printf("%d %d %d\n", digit[0],digit[1],digit[2]);
}

void intToCharString(int n, char from[], char to[]) {
    int i, sign;
    if ((sign = n) < 0) {
        n = -n;
    }

    i = 0;
    do (from[i++] = n % 10 + '0');
    while((n/=10)>0);
    size = i;
}

int intToString(int n, int from[], int to[]) {
    int i, sign, size;
    if ((sign = n) < 0) {
        n = -n;
    }

    i = 0;
    do (from[i++] = n % 10 + '0');
    while((n/=10)>0);
    size = i;
    return *from;
}

char reverseString(char from[], char to[], int size) {
    for (int i=0; i<size && from[i]!='\n'; i++) {
        to[(size-1)-i] = from[i];
    }
    return *to;
}

char convertIntToNumericBase (int digit, char string, int base) {
    return 0;
}

int power(int digit, int base) {
    int powerDigit = 1;
    for(int i=0; i<base; i++) {
        powerDigit *= digit; 
    }
    return powerDigit;
}

void convertCharToInt(char from[], int to[]) {
    for (int i=0; i<size; i++) {
        switch(from[i]) {
        case '0' : to[i] = 0 ; break;
        case '1' : to[i] = 1 ; break;
        case '2' : to[i] = 2 ; break;
        case '3' : to[i] = 3 ; break;
        case '4' : to[i] = 4 ; break;
        case '5' : to[i] = 5 ; break;
        case '6' : to[i] = 6 ; break;
        case '7' : to[i] = 7 ; break;
        case '8' : to[i] = 8 ; break;
        case '9' : to[i] = 9 ; break;
        }
    }
}

char decToHex(int digit[], char to[]) {
    for(int i=0; i<size; i++) {
        
    }
}
