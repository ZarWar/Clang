#include <stdio.h>

char lessThen (char c) {
    if(c>='a' && c<='j') {
        return c;
    } else {
        return 0;
    }
}

int main() {
    char c;
    while((c=getchar()) != EOF) {
        putchar(lessThen(c));
        // printf("\n");
    }
    return 0;
}