#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 2

// char *arr[3][1];
// char *blockArr[1];
int b = 0;
int limit = 4;
int arrCounter = 1;
int mostArr;

char* getString(void);
void reverseString(char *blockArr);
void printArr(char *blockArr);



int main() {
    int buffer = 4;
    int H = 5;
    int W = 4;
    int i = 3;
    int p = 3;



    // char **A = (char **)calloc(H, sizeof(char *));
    // for(int i = 0; i < H; i++) {
    //     A[i] = (char *)calloc(W, sizeof(char));
    // }

    // A[1][2] = 5;

    // for(int i = 0; i < H; i++) {
    //     for(int j = 0; j < W; j++) {
    //         printf("%*d", 5, A[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("\n");
    // printf("\n");
    // printf("\n");

    // H += 1;
    // A = realloc(A, H * (sizeof(char*)));
    // A[H-1] = (char *)calloc(W, sizeof(char));
    // A[H-1][2] = 5;

    // for(int i = 0; i < H; i++) {
    //     for(int j = 0; j < W; j++) {
    //         printf("%*d", 5, A[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("%lu %lu %lu\n", sizeof(char), sizeof(char**), sizeof(int**));






    // char *block = (char*)malloc(buffer*sizeof(char));
    // char *block = (char*)calloc(BUFFER, sizeof(char));
    // char *blockArr[1] = (char*)calloc(BUFFER, sizeof(char));
    char *arr[1][1] = (char*)calloc(BUFFER, sizeof(char));
    // block = "asssssssHollllle";

    // blockArr[0] = block;
    // // arr[2][0] = blockArr[0];

    // A[4][4] = 5;
    // printf("%d\n", A[4][4]);
    
    // blockArr[i] = realloc(blockArr[i], i + 1);
    arr[i][p] = realloc(arr[i][p], i + 5);
    arr[4][0] = 5;
    printf("%c\n", arr[4][0]);
    
    // printf("%s\n", blockArr[0]);
    // printf("%s\n", arr[3][0]);
    // printf("%s\n", arr[2][0]);






    // char **A = (char **)calloc(H, sizeof(char *));
    // for(int i = 0; i < H; i++) {
    //     A[i] = (char *)calloc(W, sizeof(char));
    // }

    // A[1][2] = 5;

    // for(int i = 0; i < H; i++) {
    //     for(int j = 0; j < W; j++) {
    //         printf("%*d", 5, A[i][j]);
    //     }
    //     printf("\n");
    // }





    // // int **A = (int **)malloc(H*sizeof(int *));
    // // for(int i = 0; i < H; i++) {
    // //     A[i] = (int *)malloc(W*sizeof(int));
    // // }

    // // A[1][3] = 5;

    // // for(int i = 0; i < H; i++) {
    // //     for(int j = 0; j < W; j++) {
    // //         printf("%*d", 5, A[i][j]);
    // //     }
    // //     printf("\n");
    // // }





    // printArr(blockArr[0]);


    // while(p < limit) {
    //     p++;
    //     char *block = getString();
    //     reverseString(blockArr[b]);
    //     b++;
    // }

    // for(int i=0; i<limit; i++) {
    //     printf("i=[%d] - %s\n", i, blockArr[i]);
    // }

    // int lenght = strlen(blockArr[0]);
    // printf("%d\n", lenght);

    // printArr(*blockArr);

    // printf("samijArr = %d\n", mostArr);

    // return 0;
// }

// char* getString(void) {
//     char c;
//     int i = 0;
//     int count = 1;

//     char *block = (char*)calloc(BUFFER, sizeof(char));

//     while((c = getchar()) != EOF && c != '\n') {
//         block[i++] = c;

//         if(block[0] == ' ' || block[0] == '\t') {
//             i = 0;
//         }

//         if(i >= (BUFFER * count)) {
//             count *= 2;
//             block = realloc(block, BUFFER * count);
//         }

//         // if(c == '\n') {
//         //     block[i] = '\0';
//         //     blockArr[b] = block;
//         //     printf("str 60\n");
//         // }
//     }

//     block[i] = '\0';
//     blockArr[b] = block;

//     if(i >= (BUFFER * count)) {
//         block = realloc(block, BUFFER * count + 1);
//     }

//     return blockArr[b];
// }

// void reverseString(char *blockArr) {
//     for(int y=0; y<limit; y++) {

//         int lenght = strlen(&blockArr[y]);
//         int doubleLenght = lenght * 2;

//         blockArr[y] = realloc(&blockArr[y], doubleLenght);

//         for(int i = 0; i < lenght; i++) {
//             blockArr[--doubleLenght] = blockArr[i];
//         }
//     }
// }

// void reverseString(char *block) {
//     int lenght = strlen(block);
//     int doubleLenght = lenght * 2;

//     block = realloc(block, doubleLenght);

//     for(int i = 0; i < lenght; i++) {
//         block[--doubleLenght] = block[i];
//     }
// }

// void printArr(char *blockArr) {
//     mostArr = 0;
//     // for(int i=0; i<limit-1; i++) {
//     //     if((strlen(&blockArr[i])) > (strlen(&blockArr[i+1]))) {
//     //         samijArr = blockArr[i];
//     //     }
//     // }
//     printf("str 138: %lu\n", strlen(&blockArr[0]));

//     // return strlen(&blockArr[0]);
// }