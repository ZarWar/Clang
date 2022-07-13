#include <stdio.h>

int main() {

    int i, y, p, bucket;
    int ndigit[10] = {10, 32, 0, -1, 98, 46, -20, 87, 63, 25};

    i = y = p = bucket = 0;
    
    for (i=0; i<9; i++) {
        for (y=0; y<9; y++) {
            if (ndigit[y]>ndigit[y+1]) {
                bucket=ndigit[y+1];
                ndigit[y+1]=ndigit[y];
                ndigit[y]=bucket;
            }
        }
    }

    for (p=0; p<10; p++) {
        printf("%d ", ndigit[p]);
    }

    printf("\n");

}