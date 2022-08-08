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
    int p = 0;
    while((c=getchar()) == ' ' || c == '\t') {
        printf("строка 20: getchar()==%d, '%c'\n", c, c);
    }

    s[0]=c;
    printf("строка 23: s[0]==%d, '%c'\n", s[0], s[0]);
    // s[1] = '\0';

    if(
        s[0] == HEAD ||
        s[0] == DUPLICATE ||
        s[0] == CLEAR ||
        s[0] == REPLACE
    ) {
        printf("строка 35: s[0]==%d, '%c'\n", s[0], s[0]);
    }

    if(s[0] >= 'a' && s[0] <= 'j') {
        p = 0;
        printf("попал в условие с переменной\n");
        // c = getchar();
        while((c=getchar()) == ' ' || c == '\t') { /* 'while' для хераченья сколько угодно пробелов между символом '=' и числами в момент присвоения переменной значения */
            p++;
            // if ((c=getchar()) == '\n') {
            //     printf("строка 40, количество пробелов перед числом: %d\n", p);
            // }
        }
        if (p > 0) {
            printf("строка 44, количество пробелов перед числом: %d\n", p);
        }
        // c = getchar();
        if ((c=getchar()) == '=') {
            printf("строка 51, попал в условие getchar() == '='\n");
            // s[1] = '\0';
            i = 0;
            getchar();
            if(isdigit(c)) {
                while(isdigit(s[++i] = c = getchar())) {
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