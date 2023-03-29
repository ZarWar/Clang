#include <stdio.h>

int main() {

    int i, y;
    int digits[10] = {2,6,8,3,4,9,8,2,5,1};

    printf("\nГистограмма величин массива:");

    for (i=9; i>=0; i--) {
        printf("\n");
        for (y=0; y<10; y++) {
            if (i>=digits[y]) {
                printf("  ");
            } else {
                printf(" |");
            }
        }
    }

    printf("\n");
    return 0;

}