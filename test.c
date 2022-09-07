// нужно использовать проверку if(c == EOF) {
// eof = 1;
// }
// и создать глобальную переменную int eof = 0;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 4
#define BUFSIZE 4


char c;
int eof = 0;
int bufp = 0;
int countArr = 0;
char buf[BUFSIZE];

// char* getString(void);
// void reverseString(char s[]);
void ungetch(int);
int getch(void);

int main() {
    int i = 0;
    int count = 1;
    int H = 5;
    int W = 1;

    char *block = (char*)calloc(BUFFER, sizeof(char));

    char **twoDarr = (char **)calloc(H, sizeof(char *));
    for(int i=0; i<H; i++) {
        twoDarr[i] = (char *)calloc(W, sizeof(char));
    }

    while((c = getch()) != EOF) {
        block[i++] = c;

        // if(block[0] == ' ' || block[0] == '\t') {
        //     i = 0;
        // }

        if(i >= (BUFFER * count)) {
            count *= 2;
            block = realloc(block, BUFFER * count);
        }

        if(c == '\n') {
            c = getch();
            if(c == '\n') {
                block[--i] = '\0';
                break;
            } else {
                countArr++;
                block[i++] = c;
                ungetch(c);
                block[--i] = '\0';
            }
        }
    }

    if(i >= (BUFFER * count)) {
        block = realloc(block, BUFFER * count + 1);
    }

    int lenght = strlen(block);
    int doubleLenght = lenght * 2;

    block = realloc(block, doubleLenght);

    for(int i = 0; i < lenght; i++) {
        block[--doubleLenght] = block[i];
    }

    // for(int i = 0; i < lenght; i++) {
    //     block[--doubleLenght] = block[i];
    // }

    twoDarr[countArr] = block;

    for(int i=0; i<countArr; i++) {
        printf("%s\n", twoDarr[countArr++]);
    }

    return 0;
}

// char* getString(void) {
//     int i = 0;
//     int count = 1;

//     char *block = (char*)calloc(BUFFER, sizeof(char));

//     while((c = getchar()) != EOF) {
//         block[i++] = c;

//         // if(block[0] == ' ' || block[0] == '\t') {
//         //     i = 0;
//         // }

//         if(i >= (BUFFER * count)) {
//             count *= 2;
//             block = realloc(block, BUFFER * count);
//         }
//     }

//     if(i >= (BUFFER * count)) {
//         block = realloc(block, BUFFER * count + 1);
//     }

//     if(c == '\n') {
//         block[--i] = '\0';
//     }


//     return block;
// }

// void reverseString(char *block) {
//     int lenght = strlen(block);
//     int doubleLenght = lenght * 2;

//     block = realloc(block, doubleLenght);

//     for(int i = 0; i < lenght; i++) {
//         block[--doubleLenght] = block[i];
//     }
// }

int getch(void) {
    return(bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c) {
    if(bufp >= BUFSIZE)
        printf("ungetch: слишком много символов\n");
    else
        buf[bufp++] = c;
}