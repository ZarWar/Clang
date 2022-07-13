#include <stdio.h>

void push(int a[], int x);

int b[11]={0};

int main() {
    int a[10]={1,2,3,4,5,6,7,8,9,0};
    int c = 8;
    int i,y;

    push(a, c);

    for (y=0; y<11; y++) {
        printf("%d ", b[y]);
    }
}

void push(int a[], int x) {
    int i;
    for (i=0; i<10; i++) {
        b[i]=a[i];
    }
    b[10] = x;
}