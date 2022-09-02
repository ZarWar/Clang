#include <stdio.h>

int main() {
    char c;
    while((c=getchar()) != EOF) {
        putchar(lessThen(c));
        // printf("\n");
    }
    return 0;
}

char lessThen (char c) {
    if(c>='a' && c<='j') {
        return c;
    } else {
        return 0;
    }
}