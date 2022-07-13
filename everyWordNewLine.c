#include <stdio.h>

#define IN 1
#define OUT 0

int main() {

    int c, nc, nt, nl, ns, nw, STATE;
    c = nc = nt = nl = ns = nw = 0;
    STATE = OUT;

    while (c != EOF) {
        c = getchar();

        if (c == ' ' || c == '\t') {
            STATE = OUT;
        } else if (STATE == OUT) {
            c = '\n';
            STATE = IN;
        }

        putchar(c);

    }

}