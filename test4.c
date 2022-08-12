#include <stdio.h>

int main() {
    char s[100];
    int c = getchar();
    for(int i=0; i<100; i++) {
        s[i]=0;
    }
    int i = 0;
    while(c != 'p') {
        s[i++] = c;
    }
    printf("%c\n", s[0]);
}