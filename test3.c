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
  
char      c = ' ';
int       bufp = 0;
char      ln[10][2] = {0};
char      s[MAXOP] = {0};
char      buf[BUFSIZE] = {0};

int       getop(char[]);
int       getch(void);
void      ungetch(int);

int main() {
    int i=0, y, h;
    int n;
    int p = 0; h = 0;
    
    int l = 97;
    for(int i=0; i<10; i++) {
        ln[i][0] = l++;
        printf("%c\n", ln[i][0]);
    }
    printf("\n\n");

    while((c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[0] = c;
    i = 0;

    if(s[0] >= 'a' && s[0] <= 'j') {
        for(int i=0; i<10; i++) {
            printf("str 45 i=%d\n", i);
            if(s[0] == ln[i][0]) {
                n = i;
                printf("str 48 n='%d'\n", n);
                break;
            }
        }
        if ((c=getch()) == '=') {
            s[1] = c;
            if(s[0] == 'a' && s[1] == '=') {
                printf("str 55\n");
                while(isdigit(s[i++] = c = getch()) != EOF) {
                    printf("str 57: c='%c' i='%d'\n", s[i], i);
                    if(c == '\n') {
                        s[i] = '\0';
                        break;
                    }
                }
                printf("str 63\n");
                printf("%s\n", s);
            }
        }
    }
    int result = atof(s);
    printf("str 69 '%d'\n", result);
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