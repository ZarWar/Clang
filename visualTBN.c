#include <stdio.h>

int main() {

    int c, t, s, n;
    c = t = s = 0;
    
    while (c != EOF) {
    c = getchar();

    if (c == '\t') {
        c = n;
        printf("\\t");
    } else if (c == ' ') {
        c = n;
        printf("_");
    } else if (c == '\b') {
        c = n;
        printf("\\b");
    } else if (c == '\n') {
        c = n;
        printf("\\n\n");
    }
    
    putchar(c);
    }
}