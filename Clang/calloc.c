// нужно использовать проверку if(c == EOF) {
// eof = 1;
// }
// и создать глобальную переменную int eof = 0;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 4

char* getString(void);
void reverseString(char s[]);

int main() {
    char *block = getString();
    reverseString(block);

    printf("%s\n", block);

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

    if(i >= (BUFFER * count)) {
        block = realloc(block, BUFFER * count + 1);
    }

    block[i] = '\0';

    return block;
}

void reverseString(char *block) {
    int lenght = strlen(block);
    int doubleLenght = lenght * 2;

    block = realloc(block, doubleLenght);

    for(int i = 0; i < lenght; i++) {
        block[--doubleLenght] = block[i];
    }
}