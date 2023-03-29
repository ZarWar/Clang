#include <stdio.h>

#define SIZE 5

void printArr(int arr[]);

int main() {
    int i;
    int arr[SIZE] = {5,4,3,2,1};
    printArr(arr);
    for (i=0; i<SIZE; i++) {
        printf("%d", arr[i]);
    }
}

void printArr(int array[]) {
    int b,p,bucket = 0;
    for (b=0; b<SIZE-1; b++) {
        for (p=0; p<SIZE-1; p++) {
            if (array[p]>array[p+1]) {
                bucket=array[p+1];
                array[p+1]=array[p];
                array[p]=bucket;
            }
        }  
    }
}