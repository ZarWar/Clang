#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100

#define HEAD 'H'
#define DUPLICATE 'D'
#define CLEAR 'C'
#define REPLACE 'R'

char s[MAXOP];

int main() {
    int i, y, c;
    c = ' ';
    while(c == ' ' || c == '\t') {
        c = getch();
        printf("строка 20: getch()==%d, '%c'\n", c, c);
    }
    s[0]=c;
    printf("строка 23: s[0]==%d, '%c'\n", s[0], s[0]);
    s[1] = '\0';

    if(
        s[0] == HEAD ||
        s[0] == DUPLICATE ||
        s[0] == CLEAR ||
        s[0] == REPLACE
    ) {
        printf("строка 32: s[0]==%d, '%c'\n", s[0], s[0]);
    }

    if(s[0] >= 'a' && s[0] <= 'j') {
        int p = 0;
        printf("попал в условие с переменной\n");
        // c = getch();
        while((c=getch()) == ' ' || (c=getch()) == '\t') { /* 'while' для хераченья сколько угодно пробелов между символом '=' и числами в момент присвоения переменной значения */
            p++;
            // if ((c=getch()) == '\n') {
            //     printf("строка 40, количество пробелов перед числом: %d\n", p);
            // }
        }
        if (p > 0) {
            printf("строка 44, количество пробелов перед числом: %d\n", p);
        }
        // c = getch();
        if ((c=getch()) == '=') {
            printf("попал в условие getch()=='='\n");
            // s[1] = '\0';
            i = 0;
            // getch(c);
            if(isdigit(c)) {
                while(isdigit(s[++i] = c = getch())) {
                    ;
                    for (y=0; y<i; y++) {
                        printf("строка 54: s[%d]\n", s[i]);
                    }
                }
            } else {
                ;
            }
        }
    }
}