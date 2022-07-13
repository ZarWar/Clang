#include <stdio.h>

main()
{
    int c, space;
    space = 0;

    while ((c=getchar()) != EOF) {
        if (c == ' ' && space == 0) {
            putchar(c);
            space = 1;
        }
        if (c != ' ') {
            putchar(c);
            space = 0;
        }
    }
}