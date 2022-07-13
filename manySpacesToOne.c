#include <stdio.h>

char c, sp = 0;
int n;

int main() 
{
    while (c != EOF) {
        c = getchar();

        if (c == ' ') {
            sp++;
            c = n;
        } else if (sp>0) {
            printf(" ");
            sp=0;
        }
        putchar(c);
    }
}