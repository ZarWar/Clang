#include <stdio.h>

int NDIGIT[10]

int height (int heighta[10]);

int main() {

    int c, i, y, u, b, p, hhieght, bucket;
    int ndigit[10];

    c = i = y = u = b = p = hhieght = bucket = 0;
    for (i=0; i<10; i++) {
        ndigit[i] = 0;
    }
    
    while (c != EOF) {
        c = getchar();

        if (c >='0' && c <='9') {
            ++ndigit[c - '0'];
        }

        for (b=0; b<9; b++) {
            for (p=0; p<9; p++) {
                if (ndigit[y]>ndigit[y+1]) {
                    bucket=ndigit[y+1];
                    ndigit[y+1]=ndigit[y];
                    ndigit[y]=bucket;
                    hhieght=ndigit[9];
                }
            }
        }

        if (c == '\n') {
            printf("\n");
            for (i=0; i<ndigit[1]; i++) {
                printf(" - \n");
            }
        printf(":1:\n %d\n\n", ndigit[1]);    
        }
    }
}

int height (int ndigit) {
        return NDIGIT[9];
}