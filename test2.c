#include  <stdio.h>
#include  <ctype.h>
#include  <stdlib.h>
#include  <math.h>
 
#define   MAXOP 100
#define   BUFSIZE 100
  
#define   HEAD 'H'
#define   DUPLICATE 'D'
#define   CLEAR 'C'
#define   REPLACE 'R'
  
int       c = ' ';
int       bufp = 0;
char      s[MAXOP];
char      buf[BUFSIZE];

int       getch(void);  
void      ungetch(int);

int main() {
    int i, y, c;
    int p = 0;
    while((c = getch()) == ' ' || c == '\t') {
        printf("строка 20: getch()==%d, '%c'\n", c, c);
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
        // c = getch();
        while((c=getch()) == ' ' || c == '\t') { /* 'while' для хераченья сколько угодно пробелов между символом '=' и числами в момент присвоения переменной значения */
            ;
        }
        if (c == '=') {
            // s[1] = '\0';
            printf("строка 51, попал в условие getch() == '='\n");
            i = 0;
            if(isdigit(c)) {
                while(isdigit(s[++i] = c = getch())) {
                    ;
                    for (y=0; y<10; y++) {
                        printf("строка 66: s[%d], y=%d\n", s[y], y);
                    }
                }
            } else {
                ;
            }
        }
    }
}

int getch(void) {
    return(bufp > 0) ? buf[--bufp]: getch();
}

void ungetch(int c) {
    if(bufp >= BUFSIZE)
        printf("ungetch: слишком много символов\n");
    else
        buf[bufp++] = c;
}