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
char      s[MAXOP] = {0};
char      buf[BUFSIZE] = {0};

int       getop(char[]);
int       getch(void);
void      ungetch(int);

int main() {
    int i, y, c, h;
    int p = 0; h = 2;
    c = ' ';
    while((c = getch()) == ' ' || c == '\t') {
        printf("строка 29: getch()==%d, '%c'\n", c, c);
    }

    s[0]=c;

    printf("строка 33: s[0]==%d, '%c'\n", s[0], s[0]);

    if(
        s[0] == HEAD ||
        s[0] == DUPLICATE ||
        s[0] == CLEAR ||
        s[0] == REPLACE
    ) {
        printf("строка 41: s[0]==%d, '%c'\n", s[0], s[0]);
    }

    if(s[0] >= 'a' && s[0] <= 'j') {
        p = 0;
        printf("строка 46: попал в условие с переменной\n");
        printf("строка 47: c='%c'\n", c);
        if ((c = getch()) == '=') {
            printf("строка 54: попал в условие getch() == '='\n");
            s[1] = c;
            if(s[0] == 'a' && s[1] == '=') {
                printf("строка 62: провалился в условие s[0]=='a'\n");
                c=getch();
                while(isdigit(s[h++] = c = getch()) != EOF) {
                    printf("\nстрока 64: попал в условие isdigit\n");
                    for (y=0; y<h; y++) {
                        printf("строка 66: s[%c], y=%d\n", s[y], y);
                    }
                }
            }
        }
    }
    return 0;
}

int getch(void) {
    return(bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c) {
    if(bufp >= BUFSIZE)
        printf("ungetch: слишком много символов\n");
    else
        buf[bufp++] = c;
}