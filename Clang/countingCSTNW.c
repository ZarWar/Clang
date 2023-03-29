#include <stdio.h>

#define IN 1
#define OUT 0

int main() {

    int c, nc, nt, nl, ns, nw, STATE;
    c = nc = nt = nl = ns = nw = 0;
    STATE = OUT;

    while (c != EOF) {
        c = getchar();

        if (c == '\n') {
            ++nl;
        } else if (c == '\t') {
            ++nt;
        } else if (c == ' ') {
            ++ns;
        }

        if (c != ' ' || c != '\t' || c != '\n') {
            ++nc;
        } 

        if (c == ' ' || c == '\t' || c == '\n') {
            STATE = OUT;
        } else if (STATE == OUT) {
            ++nw;
            STATE = IN;
        }

        if (c == '\n') {
        printf("%d символов, %d слов, %d пробелов, %d знаков табуляции, %d новых строк\n", nc, nw, ns, nt, nl);
        }

    }

}