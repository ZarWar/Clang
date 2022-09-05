#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 10

char *arr[BUFFER][10];
char *blockArr[BUFFER];
int b = 0;
int limit = 4;
int arrCounter = 1;

char* getString(void);
void reverseString(char s[]);
void printArr(char blockArr[]);



int main() {

    int buffer = 4;
    int H = 4;
    int W = 5;

    char **A = (char **)calloc(H, sizeof(char *));
    for(int i=0; i<H; i++) {
        A[i] = (char *)calloc(W, sizeof(char));
    }


    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            printf("%*d", 5, A[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    H++; 
    A = realloc(A, H * (sizeof(char*)));
    A[H-1] = (char *)calloc(W, sizeof(char));
    A[H-1][2] = 5;
    
    A[4][4] = 5;



    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            printf("%*d", 5, A[i][j]);
        }
        printf("\n");
    }







    // char *block2 = (char*)calloc(BUFFER, sizeof(char));
    // block2 = "asdf\0";
    // blockArr[0] = block2;
    // arr[2][1] = blockArr[0];
    // printf("%s\n", blockArr[0]);
    // printf("%s\n", arr[2][1]);
    // printf("%s\n", arr[2][0]);

    return 0;
}

char* getString(void) {
    char c;
    int i = 0;
    int count = 1;

    char *block = (char*)calloc(BUFFER, sizeof(char));

    while((c = getchar()) != EOF && c != '\n') {
        block[i++] = c;

        if(block[0] == ' ' || block[0] == '\t') {
            i = 0;
        }

        if(i >= (BUFFER * count)) {
            count *= 2;
            block = realloc(block, BUFFER * count);
        }

        // if(c == '\n') {
        //     block[i] = '\0';
        //     blockArr[b] = block;
        //     printf("str 60\n");
        // }
    }

    block[i] = '\0';
    blockArr[b] = block;

    if(i >= (BUFFER * count)) {
        block = realloc(block, BUFFER * count + 1);
    }

    return blockArr[b];
}

void reverseString(char *block) {
    int lenght = strlen(block);
    int doubleLenght = lenght * 2;

    block = realloc(block, doubleLenght);

    for(int i = 0; i < lenght; i++) {
        block[--doubleLenght] = block[i];
    }
}

void printArr(char bloackArr[]) {
    
}