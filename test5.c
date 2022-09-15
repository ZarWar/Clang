#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 10

char *arr[BUFFER][10];
char *blockArr[BUFFER];
char* getString(void);
void reverseString(char s[]);
void printArr(char blockArr[]);

int b = 0;

int main() {
    int H = 4;
    int W = 5;
    int N = 3;

    char **A = (char **)calloc(H, sizeof(char *));
    for(int i=0; i<H; i++) {
        A[i] = (char *)calloc(W, sizeof(char));
    }
    int b = 0;
    for(int i=0; i<H; i++) {
        printf("A[%d]: ", b++);
        for(int j=0; j<W; j++) {
            printf("%*d", 2, A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    A[1] = "151\0";
    A[0] = "dra\0";

    A = realloc(A, H+N * (sizeof(char*)));
    for(int i=H; i<H+N; i++) {
	A[i] = (char *)calloc(W, sizeof(char));
    }

    A[H][2] = '5';
    A[4][4] = '5';
    A[6][4] = '5';

    // printf("\n%s\n", A[1]);
    // printf("\n%s\n", A[0]);

    b = 0;
    for(int i=0; i<H+N; i++) {
        printf("A[%d]: ", b++);
        for(int j=0; j<W; j++) {
            printf("%*c", 2, A[i][j]);
        }
        printf("\n");
    }

    int f = 2;
    int s = 0;
    
    printf("%c\n", A[f][s]);

    A[f] = realloc(A[f], W * 2 * sizeof(char));
    A[f] = "12345678";

    printf("A[%d] = '%s'\n\n", f, A[f]);

//     char c;
//    while((c = getchar()) != EOF){
//	A[f][s++] = c;
//	printf("%s\n", A[0]);
//	if(s >= W) {
//	    A[f] = realloc(A[f], W * 2 * sizeof(char));
//	}
//    }

    b = 0;
    for(int i=0; i<H+N; i++) {
        printf("A[%d]: ", b++);
        for(int j=0; j<8; j++) {
            printf("%*c", 2, A[i][j]);
        }
        printf("\n");
    }

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
