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
            
            for (u=0; u<10; u++) {
                printf("\nцифра %d!; %d штуки\n", u, ndigit[u]);
                for (y=0; y<ndigit[u]; y++) {
                    printf("|");          
                }
            }
            printf("\n");
        }

    }

}