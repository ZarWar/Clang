#include <stdio.h>

int grandArrVar (int array[]);

int main() {
    int ndigit[10] = {10,65,13,6,34,89,93,2,25,1};

    printf("%d\n", grandArrVar(ndigit));
    return 0;
}

int grandArrVar (int array[]) {
    int b,p,y,i,bucket,height = 0;
    for (b=0; b<9; b++) {
            for (p=0; p<9; p++) {
                if (array[y]>array[y+1]) {
                    bucket=array[y+1];
                    array[y+1]=array[y];
                    array[y]=bucket;
                    height=array[9];
            }
        }  
    }
    for (i=0; i<10; i++) {
        printf("%d ", array[i]);
    }
    
    return height;
}