// strDebug.pl --file ./test3.c && gcc -o ./test3_O ./test3.c && ./test3_O
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
char      s[MAXOP] = {0};
char      buf[BUFSIZE] = {0};

int       getop(char[]);
int       getch(void);
void      ungetch(int);

struct    numberLetter {
          char    l;
          double  n;
          };
struct    numberLetter structArr[LETTERS] = {
          'a', '\0',
          'b', '\0',
          'c', '\0',
          'd', '\0',
          'e', '\0',
          'f', '\0',
          'g', '\0',
          'h', '\0',
          'i', '\0',
          'j', '\0'
          };

int main() {
    int count = 0;
    
    while((c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[0] = c;

    int i;
    if(s[0] >= 'a' && s[0] <= 'j') {
        for(i=0; i<LETTERS; i++) {
            count = i;
            if(s[0] == structArr[i].l) {
                break;
            }
        }
        if ((c=getch()) == '=') {
            s[1] = c;
            if(s[0] >= 'a' && s[0] <= 'j' && s[1] == '=') {
                int i = 0;
                while((c = getch()) == ' ' || c == '\t') {
                    ;
                }
                if(!isdigit(c) && c != '.' && c != '-')
                    ;

                if(c == '-') {
                    for(int i=0; i<10; i++) {
                        s[i] = '\0';
                    }
                    i = 0;
                    while(isdigit(s[i++] = c) != EOF) {
                        c = getch();
                        if(c == '\n') {
                            s[i] = '\0';
                            break;
                        }
                    }
                }

                if(isdigit(c)) {
                    for(int i=0; i<10; i++) {
                        s[i] = '\0';
                    }
                    i = 0;
                    while(isdigit(s[i++] = c) != EOF) {
                        c = getch();
                        if(c == '\n') {
                            s[i] = '\0';
                            break;
                        }
                    }
                }
            }
        }
    }
    structArr[count].n = atof(s);
    i=0;
    printf("str 101:");
    while(s[i] != '\0') {
        printf(" '%c'", s[i++]);
    }
    printf("\n");

    printf("str 107 sA[count].l='%c', sA[count].n='%g',\n", structArr[count].l, structArr[count].n);

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