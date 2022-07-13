#include <stdio.h>

int main() {
    int c,i;
    int n = 0;
    int sp = 0;
    int nl = 0;

    while ((c=getchar()) != EOF) {
        if (c == '\n') {
            if (c == ' ' || c == '\t') {
                sp++;
                c = n;
            } else if (sp>0) {
                printf(" ");
                sp=0;
            }
        }
        putchar(c);
    }
}