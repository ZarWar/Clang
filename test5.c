#include <stdio.h>

#define   BUFSIZE 100

char      buf[BUFSIZE];
int       bufp = 0;

int       getch(void);
void      ungetch(int);

int main() {

    ungetch('5');
    ungetch('4');
    ungetch('3');
    ungetch('2');
    ungetch('1');
    printf("%c\n", getch());
    printf("%c\n", getch());
    printf("%c\n", getch());
    printf("%c\n", getch());
    printf("%c\n", getch());

    printf("конец\n");
    return 0;
}

int getch(void) {
    printf("значение счётчика буфера getch %d %c\n", bufp, bufp);
    return(bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c) {
    printf("значение счётчика буфера ungetch %d %c\n", bufp, bufp);
    if(bufp >= BUFSIZE)
        printf("ungetch: слишком много символов\n");
    else
        buf[bufp++] = c;
}