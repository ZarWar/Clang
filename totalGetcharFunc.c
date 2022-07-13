#include <stdio.h>

int ndigit[10];

int sumarr (int array[]);

int main() {

    int c,i,y;
    for (i=0; i<10; i++) {
        ndigit[i] = 0;
    }

    
    while (c != EOF) {
        c = getchar();
        if (c >= '0' && c <=9) {
            ++ndigit[c - '0'];
        }

        if (c == '\n') {
            for (y=0; y<10; y++) {
            printf("%d ", ndigit[y]);
            }
            printf("\n");
            printf("sumarr %d\n", sumarr(ndigit));
            printf("\n");
        }

       
    }

    printf("%d\n", sumarr(ndigit));
    return 0;
}

int sumarr (int array[]) {
    int total,i;
    for (i=0; i<10; i++) {
        total += ndigit[i];
    }
    return total;
}