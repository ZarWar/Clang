#include  <stdio.h>
#include  <ctype.h>
#include  <stdlib.h>
#include  <math.h>
 
#define   MAXOP 100
#define   BUFSIZE 100
  
#define   NUMBER '0'
#define   HEAD 'H'
#define   DUPLICATE 'D'
#define   CLEAR 'C'
#define   REPLACE 'R'
  
int       c = ' ';
int       bufp = 0;
char      m,n, a[10][1] = {0};
char      s[MAXOP] = {0};
char      buf[BUFSIZE] = {0};

int       getop(char[]);
int       getch(void);
void      ungetch(int);

int main() {
    int i=0, y, c, h;
    int p = 0; h = 0;

    c = ' ';
    while((c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[0] = c;

    if(s[0] >= 'a' && s[0] <= 'j') {
        int m2d = s[0];
        if ((c=getch()) == '=') {
            s[1] = c;
            if(s[0] == 'a' && s[1] == '=') {
                // c=getch();
                while(isdigit(s[i++] = c = getch()) != EOF) {
                    if(s[i] == '\n') {
                        s[i] = '\0';
                        break;
                    }
                }
                printf("%s\n", s);
            }
        }
    }
    return NUMBER;
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