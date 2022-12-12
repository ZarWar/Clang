#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char intToChar     (int digit);
int  charToInt     (char digit);
char shift         (char *arr);
char reverseString (char *arr);

int ostatok = 0;

int main() {
    int H = 3;
    int W = 4;
    int n = 0;
    int i = 0;
    int y = 0;
    int fiboCount = 1;
    int fiboFirst = 1;
    int fiboSecond = 1;
    
    char **A = (char **)calloc(H, sizeof(char *));

    for(int i=0; i<H; i++) {
        A[i] = (char *)calloc(W, sizeof(char));
    }

    A[y][i] = '1';
    A[y+1][i] = '1';

    printf("%d\n", fiboFirst);
    while(fiboCount <= 10) {
        if(fiboCount % 2 == 0) {
            A[y+1][i] += A[y][i];
            printf("%d\n", A[y+1][i]);
            fiboCount++;
        } else {
            A[y][i] += A[y+1][i];
            printf("%d\n", A[y][i]);
            fiboCount++;
        }
    }

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

char shift(char *arr) {
    int lenght = strlen(arr);
    for(int i = 1; i < lenght; i++) {
        arr[i - 1] = arr[i];
    }
    arr[lenght - 1] = '\0';
    
    return *arr;
}

/* мне функция "reverseString()" уже не нужна, но пусть пока тут останется.
Планировал разворачивать массив на моменте суммирования элементов первого и второго массива.
Но понял, что могу оставить неиспользованным нулевой индекс массива, и если есть остаток от суммирования,
то переношу его в этот нулевой индекс. Нету остатка - двигаю массив на один элемент влево функцией shift().
Тоесть я только единожды двигаю массив целиком, в отличии от использования функции reverseString(),
которую бы пришлось использовать дважды */
char reverseString(char *arr) {
    int temp;
    int lenght = strlen(arr)-1;
    printf("%d\n", lenght);
    for(int i = 0; i < lenght/2; i++) {
        temp = arr[i];
        arr[i] = arr[lenght];
        arr[lenght--] = temp;
    }
    return *arr;
}