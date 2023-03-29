#include <stdio.h>

int main() {

    int c, i, nwhite, nother;
    int ndigit[10];

    c = nwhite = nother = 0;
    for (i=0; i<10; i++) {
        ndigit[i] = 0;
    }
    
    while (c != EOF) {
        c = getchar();

        if (c >='0' && c <='9') {
            ++ndigit[c - '0'];
        }

        if (c == ' ' || c == '\t' || c == '\n') {
            ++nwhite;
        } else {
            ++nother;
        }

        if (c == '\n') {
            printf("цифры - ");
            for (i=0; i<10; i++) {
                printf(" %d", ndigit[i]);
            }
            printf(";\n%d пробелов и тп;\n%d букв.\n\n", nwhite, nother);
        }

    }

}