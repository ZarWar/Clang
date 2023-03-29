#include <stdio.h>

#define SIZE 9

int main() {
    int i,r;
    // int arr[SIZE] = {1,2,3,4,5,6,7,8,9};
    int arr[SIZE] = {'a','b','c','d','e','f','d','g','h'};
    int revarr[SIZE] = {0};

    for (r=0; r<SIZE; r++) {
        revarr[(SIZE-1)-r] = arr[r];
        // if ((SIZE/2)%2 != 0) {
        //     if (r==SIZE/2) {
        //         revarr[r] = arr[r];
        //     }
        // }
        // printf("%d\n", revarr[(SIZE-1)-r]);
        printf("%c", revarr[(SIZE-1)-r]);
    }
    printf("\n");
    for (i=0; i<SIZE; i++) {
        // printf("%d", revarr[i]);
        printf("%c", revarr[i]);
    }
    printf("\n");
}