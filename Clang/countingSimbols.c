#include <stdio.h>

int main() {

    int c, t, s, n;
    c = t = s = n = 0;
    

    while (c != EOF) {
    c = getchar();

    if (c == ' ') {
        s++;
    } else if (c == '\t') {
        t++;
    } else if (c == '\n') {
        n++;
    }
    
    putchar(c);

    if (c == '\n') {
        printf("\n- %d пробелов\n- %d табуляци\n- %d новых строк\n\n", s, t, n);
    }
    
    }
}