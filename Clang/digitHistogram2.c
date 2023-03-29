#include <stdio.h>

int main() {

    int c, i, y, u, nwhite, nother;
    int ndigit[10];

    c = i = y = u = 0;
    for (i=0; i<10; i++) {
        ndigit[i] = 0;
    }
    
    while (c != EOF) {
        c = getchar();

        if (c >='0' && c <='9') {
            ++ndigit[c - '0'];
        }

        if (c == '\n') {
            printf("\nцифра 1!; %d штуки\n", ndigit[1]);
            for (i=0; i<ndigit[1]; i++) {
                printf("|");    
                
                       
            }
            printf("\n");
        }

    }

}