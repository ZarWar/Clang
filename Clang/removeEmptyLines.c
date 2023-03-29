#include <stdio.h>

char c, sp = 0;
int n = 0;
int pc = 0;

int main() 
{
    while ((c=getchar()) != EOF) {
        if (c!='\n' || pc!='\n' && c=='\n') {
            putchar(c);
        }
        pc = c;
    }
}

// pc == '\n' && c != '\n' || pc != '\n' && c != '\n' || pc != '\n' && c == '\n'
// c!='\n' && (pc=='\n' || pc!='\n') || pc!='\n' && c=='\n'

// pc == '\n' = A;
// c != '\n' = B;
// pc != '\n' = C;
// c == '\n' = D;
// A*B + C*B + C*D = B*(A+C)+C*D = B + C*D