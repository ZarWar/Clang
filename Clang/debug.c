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
// int       sizeofStructArr = (sizeof(structArr) / sizeof(structArr[0]));

int main() {
    int y, h;
    int p = 0; h = 0;
    int count = 0;
    int c = ' ';
    while((c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[0] = c;
    printf("str 52 '%c'\n", s[0]);

    int i;
    if(s[0] >= 'a' && s[0] <= 'j') {
        for(i=0; i<LETTERS; i++) {
            count = i;
            printf("str 57 i=%c\n", structArr[i].l);
            if(s[0] == structArr[i].l) {
                printf("str 59 count='%d'\n", count);
                break;
            }
        }

        if ((c=getch()) == '=') {
            s[1] = c;
            if(s[0] >= 'a' && s[0] <= 'j' && s[1] == '=') {
                printf("str 67\n");
                int i = 0;
                // s[0] = '1';
                // ungetch(c);
                printf("str 71 '%c'\n", c);

                while((c = getch()) == ' ' || c == '\t') {
                    printf("str 75\n");
                    ;
                }
                
                printf("str 79\n");
                if(!isdigit(c) && c != '.' && c != '-')
                    printf("str 81\n");
                    ;

                if((c=getch()) == '-') {
                    printf("str 85\n");
                    while(isdigit(s[++i] = c = getch()));
                    if(i == 1) { /* зачем здесь эта проверка? */
                        ungetch(c);
                    }
                }





                printf("str 96\n");
                if(isdigit(c)) {
                    i = 0;
                    printf("str 95 s[0]='%c', s[1]='%c', s[2]='%c'\n", s[0], s[1], s[2]);
                    while(isdigit(s[i++] = c = getch()) != EOF) {
                        printf("str 96: c='%c' i='%d'\n", s[i], i);
                        if(c == '\n') {
                            s[--i] = '\0';
                            break;
                        }
                    }
                }
                
                printf("str 106 '%s'\n", s);
            }
        } else {
            ;
        }
    }
    structArr[count].n = atof(s);
    printf("str 110 sA[count].l='%c', sA[count].n='%g',\n", structArr[count].l, structArr[count].n);

    // if(!isdigit(c) && c != '.' && c != '-')
    //     return c;

    // i = 0;

    // if(c == '-') {
    //     while(isdigit(s[++i] = c = getch()));
    //     if(i == 1) { /* зачем здесь эта проверка? */
    //         ungetch(c);
    //         return '-';
    //     }
    // }

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