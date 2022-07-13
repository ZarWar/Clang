#include <stdio.h>

#define SPSIZE 4

int main() 
{
    int c,sp,pc;
    sp = 0;
    while (c != EOF) {
        c = getchar();
        if (c == ' ') {
            sp++;
        }
        
        if (pc != ' ' && c != ' ') {
            putchar(c);
        } else if (pc == ' ' && c != ' ') {
            for (int i=(sp/SPSIZE); i>0; i--) {
                    printf("\t");
            }
            for (int m = sp % SPSIZE; m > 0; m--) {
                printf("_");
            }
            sp = 0;
            putchar(c);
        }

        pc = c;

        // if (c == ' ') {
        //     sp++;
        //     printf("\n---> %d", sp);
        // } else if (sp < SPSIZE) {
        //     for (int i = 0; i < sp; i++) {
        //         printf("_");
        //     }
        //     putchar(c);
        //     sp = 0;
        // } else if (sp == SPSIZE) {
        //     printf("\t");
        //     putchar(c);
        //     sp = 0;
        // } else {
        //     putchar(c);
        // } 


        // } else if (c != ' ' && sp == 1) {
        //     printf("_");
        //     putchar(c);
        //     sp=0;
        // } else if (c != ' ' && sp == 2) {
        //     printf("__");
        //     putchar(c);
        //     sp=0;
        // } else if (c != ' ' && sp == 3) {
        //     printf("___");
        //     putchar(c);
        //     sp=0;
        // } else if (c != ' ' && sp == SPSIZE) {
        //     printf("\t");
        //     putchar(c);
        //     sp=0;
        // } else {
        //     putchar(c);
        // }

        // printf("----> %d\n", sp);
    }
}