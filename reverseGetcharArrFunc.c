#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ARRSIZE 1000

char reverse(char from[], char to[], int size);

int main() {
    int i;
    char c;
    char from[ARRSIZE] = {0};
    char to[ARRSIZE] = {0};

    for (i=0; (c=getchar()) && i<ARRSIZE; i++) {
        from[i] = c;
        if (c == '\n') {
            reverse(from, to, i);
            printf("%s\n", to);

            memset(from,0,100);
            memset(to,0,100);

            i=-1;
        }
    }
    return 0;
}

char reverse(char from[], char to[], int size) {
    for (int i=0; i<size && from[i]!='\n'; i++) {
        to[(size-1)-i] = from[i];
    }
    return *to;
}