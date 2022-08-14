#include <stdio.h>

#define SIZE 5

int concat(int x, int y);
int concatArr(int *arr, int size);

int main() {
    int c, b, i;
    int arr[SIZE] = {8,2,3,4,6};
    concatArr(arr, SIZE);
}

int concat(int x, int y) {
    int temp = y;
    while (y != 0) {
        x *= 10;
        y /= 10;
    }
    return x + temp;
}

int concatArr(int *arr, int size) {
    int i,c,b;
    for (i=0; i<size; i++) {
        if (i%2=='0') {
            c = concat(arr[i], arr[i+1]);
            b = concat(c,b);
            i++;
        } else {
            b = concat(b,arr[i]);
        } 
    }
    printf("%d\n", b);
    return b;
}