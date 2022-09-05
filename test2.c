#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 10

char *arr[BUFFER][10];
char *blockArr[BUFFER];
int b = 0;
int limit = 4;
int arrCounter = 1;
int mostArr;

char* getString(void);
void reverseString(char *blockArr);
void printArr(char *blockArr);



int main() {
    int p = 0;

    // char *block2 = (char*)calloc(BUFFER, sizeof(char));
    // block2 = "asdf\0";
    // blockArr[0] = block2;
    // arr[2][1] = blockArr[0];
    // printf("%s\n", blockArr[0]);
    // printf("%s\n", arr[2][1]);
    // printf("%s\n", arr[2][0]);
    // printArr(blockArr[0]);


    while(p < limit) {
        p++;
        char *block = getString();
        reverseString(blockArr[b]);
        b++;
    }

    for(int i=0; i<limit; i++) {
        printf("i=[%d] - %s\n", i, blockArr[i]);
    }

    int lenght = strlen(blockArr[0]);
    printf("%d\n", lenght);

    printArr(*blockArr);

    printf("samijArr = %d\n", mostArr);

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

void reverseString(char *block) {
    int lenght = strlen(block);
    int doubleLenght = lenght * 2;

    block = realloc(block, doubleLenght);

    for(int i = 0; i < lenght; i++) {
        block[--doubleLenght] = block[i];
    }
}

void printArr(char *blockArr) {
    mostArr = 0;
    // for(int i=0; i<limit-1; i++) {
    //     if((strlen(&blockArr[i])) > (strlen(&blockArr[i+1]))) {
    //         samijArr = blockArr[i];
    //     }
    // }
    printf("str 122: %lu\n", strlen(&blockArr[0]));

    // return strlen(&blockArr[0]);
}