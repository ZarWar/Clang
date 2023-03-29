#include <stdio.h>

#define SIZE 9

int revarr[SIZE]={0};
void reverse(int arr[], int size);

int main() {
    int i;
    int arr[SIZE] = {'a','b','c','d','e','f','d','g','h'};
    reverse(arr, SIZE);
    
    for (i=0; i<SIZE; i++) {
        printf("%c", revarr[i]);
    }
}

void reverse(int arr[], int size) {
    int r;

    for (r=0; r<SIZE; r++) {
        revarr[(SIZE-1)-r] = arr[r];
    }
}