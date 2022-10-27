#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 4

int spaceCount(int lenght, int maxstrLenght);
void printEtoGovno(char *A, int N);
void reverseString(char *A);

int main() {
    int i = 0;
    int y = 0;

    char c, lastinputChar;
    int H = 1;
    int W = 4;

    int sizeArr = 0;

    // 17-22 аллоцироуем память под двумерный массив
    char **A = (char **)calloc(H, sizeof(char *));

    for(int i=0; i<H; i++) {
        A[i] = (char *)calloc(W, sizeof(char));
    }

    i = 0;
    while((c = getchar()) != EOF) {
        lastinputChar = c;

        if(c == '\n') {
            // реаллоцируем память под один символ - символ переноса строки
            if(i >= W - 1) {
                W += 1;
                A[y] = (char *)realloc(A[y], W * sizeof(char));
            }
            A[y][i++] = '\0';

            W = 4;
            i = 0;

            // реаллоцируем память х2 под первое измерение массива (в высоту)
            if(y >= H - 1) {
                H *= 2;
                A = (char **)realloc(A, H * sizeof(char *));

                for(int t = H / 2; t < H; t++) {
                    A[t] = (char *)calloc(W, sizeof(char));
                }
            }

            y++;
            
        } else {
            // реаллоцирруем память х2 под второе измерение (в ширину)
            if(i >= W - 1) {
                W *= 2;
                A[y] = (char *)realloc(A[y], W * sizeof(char));
            }

            A[y][i++] = c;
        }
    }

    // реаллоцируем память под +1 символ в ширину, если необходимо
    if(i >= W - 1) {
        W += 1;
        A[y] = (char *)realloc(A[y], W * sizeof(char));
    }
    A[y][i++] = '\0';


    // выявляем самую длинную строку, и сохраняем результат в числовую переменную
    int maxstrLen = 0;
    for(i = 0; i < y; i++) {
        int currentLen = strlen(A[i]);

        while(A[i][--currentLen] == ' ') {
            ;
        }
        A[i][currentLen + 1] = '\0';

        // printf("strlen(A[i]) = %lu\n", strlen(A[i]));
        if (maxstrLen < strlen(A[i])) {
            maxstrLen = strlen(A[i]);
        }
    }

    for(int i = 0; i < y; i++){
        printEtoGovno(A[i], spaceCount(strlen(A[i]), maxstrLen));
    }

    for(int i = y - 1; i >= 0; i--){
        printEtoGovno(A[i], spaceCount(strlen(A[i]), maxstrLen));
    }
    
    return 0;
}

int spaceCount(int lenght, int maxstrLenght) {
    return (maxstrLenght - lenght) * 2;
}

void printEtoGovno(char *A, int N) {
    printf("%s", A);

    for (int i = 0; i < N; i++) {
        printf(" ");
    }

    for (int i = strlen(A)-1; i >= 0; i-- ) {
        printf("%c", A[i]);
    }

    printf("\n");
}