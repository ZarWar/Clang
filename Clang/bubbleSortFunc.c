#include <stdio.h>

#define SIZE 10

int grandArrVar (int *array);
int main() {
    int c, i, y, u, b, p, hhieght, bucket;
    c = i = y = u = b = p = hhieght = bucket = 0;
    int ndigit[10] = {10, 32, 0, -1, 98, 46, -20, 87, 63, 25};
    int ndigit2[10] = {0, 1, 2, 12, 4, 5, 6, 7, 8, 9};

    printf("%d\n", grandArrVar(ndigit));
    printf("%d\n", grandArrVar(ndigit2));
    
    for (p=0; p<10; p++) {
        printf("%d ", ndigit[p]);
    }
    printf("\n");

    for (i=0; i<10; i++) {
        printf("%d ", ndigit2[i]);
    }
    printf("\n");

    return 0;
}

int grandArrVar (int *array) {
    int b,p,c,bucket,height = 0;
    int array2[SIZE];

    for (c=0; c<SIZE; c++) {
        array2[c]=array[c];
    }
    
    for (b=0; b<SIZE-1; b++) {
        for (p=0; p<SIZE-1; p++) {
            if (array2[p]>array2[p+1]) {
                bucket=array2[p+1];
                array2[p+1]=array2[p];
                array2[p]=bucket;
            }
        }  
    }
    height=array2[9];
    return height;
}