#include <stdio.h>

void reverseInt(int n, char s[]);

int main() {
    int n = 168;
    char s[10] = {0};
    reverseInt(n, s);
    printf("%s\n", s);
}

void reverseInt(int n, char s[]) {
    int i, sign;
    if ((sign = n) < 0) {
    n = -n;
    }   

    i=0;
    do (s[i++] = n % 10 + '0');
    while((n/=10)>0);
    if (sign < 0) {
        s[i++] = '-';
        s[i] = '\0';
    }
}