#include <stdio.h>
#define LIMIT 1000

int main() {
    char arr[LIMIT] = {0};
    int c, i, y, g;
    i = 0;
    int t = '-';

    while (c != EOF) {
        c = getchar();
        i++;
        if (i%30==0) {
            if (c == ' ') {
                c = '\n';
            } else {
                g = c;
                putchar(g);
                putchar(t);
                c = '\n';
            }
        }
        if (c == '\n') {
            i = 0;
        }
        putchar(c);
    }
}

