#include <stdio.h>

main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            printf("\\n\n");
        }
        else if (c == '\\') {
            printf("\\\\");
        }
        else if (c == '\t') {
            printf("\\t");
        }
        else {
            putchar(c);
        }
    }
}