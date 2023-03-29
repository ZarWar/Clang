#include <stdio.h>

int concat(int x, int y);
int concatArr(int arr[]);
int CtoF (int cels);

int main() {

    int c, b, i, y, o, g;
    b = 0;
    int digits[5];
    for (o=0; o<5; o++) {
        digits[o]=0;
    }


    while (g != EOF) {
        g = getchar();
        if (g == ' ' || g == '\t' || g == '\n') {
            ;
        } else if (g <= 9 && g >= 0) {
            for (y=0; y<5; y++) {
                digits[y]=g - '0';
            }
        }

        if (g == '\n') {
            for (i=0; i<4; i++) {
                if (i%2=='0') {
                    c = concat(digits[i], digits[i+1]);
                    b = concat(c,b);
                    i++;
                } else {
                    b = concat(b,digits[i]);
                } 
            printf("%d \n", b);
            }
        printf("%d \n", b);
        }
        // printf("%d \n", CtoF(b));
    }

}

int concat(int x, int y) {
    int temp = y;
    while (y != 0) {
        x *= 10;
        y /= 10;
    }
    return x + temp;
}

int CtoF (int cels) {
    int fahr = (cels * 1.8) + 32;
    return fahr;
}