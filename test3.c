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

    int i;
    if(s[0] >= 'a' && s[0] <= 'j') {
        for(i=0; i<LETTERS; i++) {
            printf("str 58 i=%c\n", structArr[i].l);
            if(s[0] == structArr[i].l) {
                printf("str 60 count='%d'\n", count);
                break;
            }
        }
        count = i;

        if ((c=getch()) == '=') {
            s[1] = c;
            if(s[0] >= 'a' && s[0] <= 'j' && s[1] == '=') {
                printf("str 67\n");
                int i = 0;
                // ungetch(c);
                // c = getch();
                printf("str 71 '%c'\n", c);

                while((c = getch()) == ' ' || c == '\t') {
                    ;
                }
                
                if(!isdigit(c) && c != '.' && c != '-')
                    ;

                if((c=getch()) == '-') {
                    while(isdigit(s[++i] = c = getch()));
                    if(i == 1) { /* зачем здесь эта проверка? */
                        ungetch(c);
                    }
                }

                if(isdigit(c)) {
                    while(isdigit(s[++i] = c = getch()) != EOF) {
                        printf("str 69: c='%c' i='%d'\n", s[i], i);
                        if(c == '\n') {
                            s[i] = '\0';
                            break;
                        }
                    }
                }
                

                
                printf("str 75\n");
                printf("%s\n", s);
            }
        } else {
            ;
        }
    }
    structArr[count].n = atof(s);
    printf("str 83 sA[count].l='%c', sA[count].n='%g',\n", structArr[count].l, structArr[count].n);

    if(!isdigit(c) && c != '.' && c != '-')
        return c;

    i = 0;
    if(c == '-') {
        while(isdigit(s[++i] = c = getch()));
        if(i == 1) { /* зачем здесь эта проверка? */
            ungetch(c);
            return '-';
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