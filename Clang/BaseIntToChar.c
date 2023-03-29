#include <stdio.h>

void itob(int n, char s[], int b);
char convertIntToChar(int from);

int size = 0;

int main() {
    int n = 47690;
    char s[30] = {0};
    itob(n, s, 16);
}

void itob(int n, char s[], int b) {
    int i = 0;
    do (s[i++] = convertIntToChar(n % b));
    while((n/=b)>0);
    int size = i;

    for (int y=0; y<i/2; y++) {
        int temp = s[y];
        s[y] = s[i-y-1];
        s[i-y-1] = temp;
    }

    for (int y=0; y<size; y++) {
        printf("%c ", s[y]);
    }
}

char convertIntToChar(int from) {
    char to;

    if (from >= 10 && from <= 15) {
        return ('A' - 10 + from);
    }
    return (from + '0');
}