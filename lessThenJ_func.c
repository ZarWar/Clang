#include <stdio.h>

char lessThen (char c);

int main() {
    char c;
    while((c=getchar()) != EOF) {
        putchar(lessThen(c));
        printf("\n");
    }
    return 0;
}

char lessThen (char c) {
    if(c>='a' && c<='j') {
        return c;
    } else if (c == '\n') {
        c = '\0';
    } else {
        return 0;
    }
    return 0;
}