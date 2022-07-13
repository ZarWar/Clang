#include <stdio.h>

int main ()
{
    int c, state;
    state = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == 0) {
                ;
            }
            else {
                state = 0;
                printf("\n");
            }
        }    
        else {
            putchar(c);
            state = 1;
        }
    }
}