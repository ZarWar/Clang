#include <stdio.h>

int sumarr (int array[]);

int main() {

    int ndigit[10] = {10,65,13,6,34,89,93,2,25,1};

    printf("%d\n", sumarr(ndigit));
    return 0;

}

int sumarr (int array[]) {

    int total,i;
    for (i=0; i<10; i++) {
        total += array[i];
    }
    return total;

}