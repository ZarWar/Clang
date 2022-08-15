#include  <stdio.h>
#include  <ctype.h>
#include  <stdlib.h>
#include  <math.h>
 
#define   MAXOP 100
#define   BUFSIZE 100
#define   LETTERS 10
  
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

struct    nl {
          char l[LETTERS];
          int  n[MAXOP];
          };

int main() {
    int i=0, y, h;
    int n;
    int p = 0; h = 0;


    struct nl letterNumber;
    int aLetter = 97;
    for(int i=0; i<LETTERS; i++) {
        letterNumber.l[i] = aLetter++;
    }
    letterNumber.n[MAXOP] = {0};

    while((c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[0] = c;
    i = 0;

    if(s[0] >= 'a' && s[0] <= 'j') {
        for(int i=0; i<LETTERS; i++) {
            printf("str 45 i=%d\n", i);
            if(s[0] == letterNumber.l[i]) {
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
        } else {
            ;
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