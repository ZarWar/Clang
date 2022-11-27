#include <stdio.h>
#include <string.h>

char intToChar (int digit);
int  charToInt (char digit);

int ostatok;

int main() {
    int H = 2;
    int W = 4;
    
    char **A = (char **)calloc(H, sizeof(char *));

    for(int i=0; i<H; i++) {
        A[i] = (char *)calloc(W, sizeof(char));
    }

    char slagaemoe1[5] = {0};
    char slagaemoe2[5] = {0};
    char summa[10] = {0};

    int ostatok = 0;
    int ktoBolshe = 0;

    int digit1;
    int digit2;
    int digit3;
    int temp1;
    int temp2;

    printf("введи первое суммируемое:\n");
    scanf("%s", slagaemoe1);
    printf("\nвведи второе суммируемое:\n");
    scanf("%s", slagaemoe2);

    printf("\n");
    printf("slag1 = '%s'\n", slagaemoe1);
    printf("slag2 = '%s'\n", slagaemoe2);

    printf("\n");
    printf("strlen1 = %lu\n", strlen(slagaemoe1));
    printf("strlen2 = %lu\n", strlen(slagaemoe2));

    if(strlen(slagaemoe1) > strlen(slagaemoe2)) {
        ktoBolshe = strlen(slagaemoe1);
    } else {
        ktoBolshe = strlen(slagaemoe2);
    }
     
    printf("ktoBolshe = '%d'\n", ktoBolshe);

    for(int i = ktoBolshe - 1; i >= 0; i--) {
        digit3 = charToInt(slagaemoe1[i]) + charToInt(slagaemoe2[i]);
        if(digit3 % 10 != 0) {
            temp2 = digit3 / 10;
            temp1 = digit3 % 10;
        }

        if (temp2 != 0) {
            ostatok = temp2;
        } else {
            ostatok = 0;
        }

        summa[i] = intToChar(temp1 + ostatok);
    }
    printf("summa = %s\n", summa);

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