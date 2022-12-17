// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597,
// 100-е число фибоначии = 218922995834555169026

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct digities {
    int digitCount;
    int byteSize;
    char *digitArr;
} bigInt;

char   intToChar     (int digit);
int    charToInt     (char digit);
char   shift         (char *arr);
void   reverseString (bigInt A);
char   charSum       (char *arr);
bigInt bigDigitInit  (int firstDigit);
bigInt bigDigitSum   (bigInt A, bigInt B);
void   printBigInt   (bigInt digit);
void   dump          (bigInt digit);

int ostatok = 0;

int main() {
    int W = 4;
    int i = 0;
    int y = 0;

    bigInt FirstS = bigDigitInit(0);
    bigInt SecondS = bigDigitInit(1);

    for(int i = 0; i < 999; i++) { /* цикл здесь работает до 1000-го числа фибоначчи,
    потому что мы пропускаем начальную последовательность, при которой число равно "0"  */ 
        
        bigInt TempS = SecondS;  // большее значение переливается в темпоральную структуру (3)
        SecondS = bigDigitSum(FirstS, SecondS); // к большему значению суммируется малое (2 + 3 = 5)
        FirstS = TempS; // большее предыдущее значение становится теперь малым (3)
    }

    return 0;
}

bigInt bigDigitInit(int firstDigit) {
    bigInt A;

    A.digitCount = 1;
    A.byteSize = 2;
    A.digitArr = (char *)calloc(A.byteSize, sizeof(char));
    A.digitArr[0] = firstDigit;

    return A;
}

bigInt bigDigitSum (bigInt A, bigInt B) {
    bigInt C;

    if(A.digitCount  > B.digitCount) {
        C.byteSize   = A.digitCount + 1; // +1 - для +1 регистра в сумме
        C.digitCount = A.digitCount;
    } else {
        C.byteSize   = B.digitCount + 1; // +1 - для +1 регистра в сумме
        C.digitCount = B.digitCount;
    }

    C.digitArr = (char *)calloc(C.byteSize, sizeof(char));

    reverseString(A);
    reverseString(B);

    int ostatok = 0;
    int i;

    for(i = 0; i < C.digitCount; i++) { // разобраться, как этот цикл должен работать. Здесь не должен быть byteSize.
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
        C.digitArr[i] = 1;
    }

    reverseString(C);

    // из за отсутствия этих двух реверсов был "затык" в решении
    reverseString(A); // добавил этот реверс, потому что на 75 строке не реверсировал обратно
    reverseString(B); // добавил этот реверс, потому что на 76 строке не реверсировал обратно

    printBigInt(C);
    dump(A);
    dump(B);

    return C;
}

void printBigInt(bigInt A) {
    for(int i = 0; i < A.digitCount; i++) {
        printf("%d", A.digitArr[i]);
    }
    printf("\n");
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

char shift (char *arr) {
    int lenght = strlen(arr);
    for(int i = 1; i < lenght; i++) {
        arr[i - 1] = arr[i];
    }
    arr[lenght - 1] = '\0';
    
    return *arr;
}

void reverseString(bigInt A) {
    if (A.digitCount == 1) {
        return;
    }

    int temp;
    int lenght = A.digitCount - 1;
    for(int i = 0; i < A.digitCount/2; i++) {
        temp = A.digitArr[i];
        A.digitArr[i] = A.digitArr[lenght-i];
        A.digitArr[lenght-i] = temp;
    }
}

void dump (bigInt A) {
    printf(".digitArr   = ");
    for(int i = 0; i < A.digitCount; i++) {
        printf("%d", A.digitArr[i]);
    }
    printf("\n");

    printf(".digitCount = %d\n", A.digitCount);
    printf(".byteSize   = %d\n", A.byteSize);
    printf("\n");
}