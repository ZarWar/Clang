#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 4

int main() {
    int i = 0;
    int y = 0;

    char c, lastinputChar;
    int H = 1;
    int W = 4;

    int sizeArr = 0;

    char **A = (char **)calloc(H, sizeof(char *));

    for(int i=0; i<H; i++) {
        A[i] = (char *)calloc(W, sizeof(char));
    }

    i = 0;
    while((c = getchar()) != EOF) {
        lastinputChar = c;

        if(c == '\n') {
            if(i >= W - 1) {
                W += 1;
                A[y] = (char *)realloc(A[y], W * sizeof(char));
            }
            A[y][i++] = '\0';

            W = 4;
            i = 0;

            if(y >= H - 1) {
                H *= 2;
                A = (char **)realloc(A, H * sizeof(char *));

                for(int t = H / 2; t < H; t++) {
                    A[t] = (char *)calloc(W, sizeof(char));
                }
            }

            y++;
            
        } else {
            if(i >= W - 1) {
                W *= 2;
                A[y] = (char *)realloc(A[y], W * sizeof(char));
            }

            A[y][i++] = c;
        }
    }

    if(i >= W - 1) {
        W += 1;
        A[y] = (char *)realloc(A[y], W * sizeof(char));
    }
    A[y][i++] = '\0';

    int maxstrLen = 0;
    for(i = 0; i < y; i++) {
        if (maxstrLen < strlen(A[i])) {
            maxstrLen = strlen(A[i]);
        }
    }

    int doubleLen = (maxstrLen + 1) * 2 - 1;

    for(i = 0; i < y; i++) {
        A[i] = (char *)realloc(A[i], doubleLen * sizeof(char));
        
        int zaebal = strlen(A[i]);
        while(zaebal < doubleLen - 1) {
            A[i][zaebal++] = ' ';
        }

        for(int u = 0; u < (doubleLen - 1) / 2; u++) {
            A[i][doubleLen - u - 2] = A[i][u];
        }
        A[i][doubleLen - 1] = '\0';
        
        printf("%s\n", A[i]);
    }

    for(int r = y - 1; r >= 0; r--) {
        printf("%s\n", A[r]);
    }

    return 0;
}

// 1) в самой длинной строке избавляться от пробелов в конце
// 2) переписать, чтобы не понадобилась вторая реаллокация (на 75 строке)
// тоесть нужно сразу считать количество символов в строке