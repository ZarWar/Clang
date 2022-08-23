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
    printf("str 53 '%c'\n", s[0]);

    int i;
    if(s[0] >= 'a' && s[0] <= 'j') {
        for(i=0; i<LETTERS; i++) {
            count = i;
            printf("str 59 i='%c'\n", structArr[i].l);
            if(s[0] == structArr[i].l) {
                printf("str 61 count='%d'\n", count);
                break;
            }
        }
        if ((c=getch()) == '=') {
            s[1] = c;
            if(s[0] >= 'a' && s[0] <= 'j' && s[1] == '=') {
                printf("str 68\n");
                int i = 0;
                printf("str 70 '%c'\n", c);
                while((c = getch()) == ' ' || c == '\t') {
                    printf("str 72: c=' '\n");
                    ;
                }
                printf("str 75\n");
                printf("str 76: ungetch(c)=%c\n", c);
                if(!isdigit(c) && c != '.' && c != '-')
                    printf("str 78\n");
                    ;
                printf("str 80: ungetch(c)=%c\n", c);
                // if((c=getch()) == '-') {
                //     printf("str 82\n");
                //     while(isdigit(s[++i] = c = getch()));
                //     if(i == 1) { /* зачем здесь эта проверка? */
                //         ungetch(c);
                //     }
                // }
                printf("str 88: ungetch(c)=%c\n", c);
                // ungetch(c);
                printf("str 90: ungetch(c)=%c\n", c);
                if(isdigit(c)) {
                    for(int i=0; i<10; i++) {
                        s[i] = '\0';
                    }
                    i = 0;
                    printf("str 96 s[0]='%c','%c','%c','%c','%c'\n", s[0], s[1], s[2], s[3], s[4]);
                    while(isdigit(s[i++] = c) != EOF) {
                        c = getch();
                        printf("\n");
                        printf("str 100 s[0]='%c','%c','%c','%c','%c'\n", s[0], s[1], s[2], s[3], s[4]);
                        printf("str 101: c='%c' i='%d'\n", s[i], i);
                        printf("str 102: ungetch(c)=%c\n", c);
                        printf("\n");
                        if(c == '\n') {
                            s[i] = '\0';
                            break;
                        }
                    }
                }
                printf("str 110 '%s'\n", s);
            }
        } else {
            ;
        }
    }
    structArr[count].n = atof(s);
    printf("str 117 s[0]='%c','%c','%c','%c','%c'\n", s[0], s[1], s[2], s[3], s[4]);
    printf("str 118 sA[count].l='%c', sA[count].n='%g',\n", structArr[count].l, structArr[count].n);

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