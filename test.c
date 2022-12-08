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
bigInt bigDigInit();
void printBigInt(bigInt);
bigInt sumBigInt(bigInt, bigInt);
void reverseString (bigInt);

int main() {
    bigInt A = bigDigInit();
    bigInt B = bigDigInit();
    
    printBigInt(A);
    printBigInt(B);
    bigInt D = sumBigInt(A, B);
    printBigInt(D);

    return 0;
}

bigInt bigDigInit() {
    bigInt dick;
    dick.digitCount = 0;
    dick.byteSize = 10;
    dick.digitArr = (char *)calloc(dick.byteSize, sizeof(char));

    int c;
    while((c = getchar()) != '\n') {
        if(dick.digitCount >= dick.byteSize) {
            dick.byteSize += 10;
            dick.digitArr = (char *)realloc(dick.digitArr, dick.byteSize * sizeof(char));
        }
        dick.digitArr[dick.digitCount++] = c - 48;
    }

    return dick;
}

void printBigInt(bigInt digit) {
    for(int i = 0; i < digit.digitCount; i++) {
        printf("%d", digit.digitArr[i]);
    }
    printf("\n");
}

bigInt sumBigInt(bigInt A, bigInt B) {
    bigInt C;
    if(A.digitCount > B.digitCount) {
        C.byteSize = A.digitCount + 1; // +1 - для +1 регистра в сумме
    } else {
        C.byteSize = B.digitCount + 1; // +1 - для +1 регистра в сумме
    }

    C.digitCount = 0;
    C.digitArr = (char *)calloc(C.byteSize, sizeof(char));

    reverseString(A);
    reverseString(B);

    int ostatok = 0;
    int i;

    for(i = 0; i < C.byteSize; i++) { // разобраться, как этот цикл должен работать. Здесь не должен быть byteSize.
        C.digitCount++;
        int sum = A.digitArr[i] + B.digitArr[i] + ostatok;

        if(sum >= 10) {
            C.digitArr[i] = sum - 10;
            ostatok = 1;
        } else {
            C.digitArr[i] = sum;
            ostatok = 0;
        }
    }

    if(ostatok == 1) {
        C.digitCount++;
        C.digitArr[++i] = 1;
    }

    reverseString(C);

    return C;
}

void reverseString(bigInt A) {
    int temp;
    int lenght = A.digitCount - 1;
    for(int i = 0; i < A.digitCount/2; i++) {
        temp = A.digitArr[i];
        A.digitArr[i] = A.digitArr[lenght-i];
        A.digitArr[lenght-i] = temp;
    }
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