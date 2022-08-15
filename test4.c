#include <stdio.h>



int main() {
    int l = 97;
    int f;
    char a[3][2];
    for(int i=0; i<3; i++) {
        a[i][0] = l++;
    }
    printf("%c\n", a[0][0]);
    while((f=0) <= a) {
        printf("длина массива=%d\n", f);
    }
    return 0;
}