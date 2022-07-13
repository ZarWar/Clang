#include <stdio.h>

// #define ARR 10

int main()
{
        int c, i, count;
        int words[10];
        count = 0;

        for (i=1; i<=10; ++i) {
                words[i]=0;
        }

        while ((c=getchar()) != EOF) {
                if (c !=' ' && c !='\t' && c != '\n') {
                        ++count;
                } else if (count > 0 && count <= 9) {
                        ++words[count];
                        count = 0;
                } else if (count > 9) {
                        ++words[10];
                        count = 0;
                }
        }
        printf("number of chars in words\n");
        for(i=1; i<11; ++i) {
                printf("%d %d ", i, words[i]);
                while (words[i] > 0) {
                        printf("|");
                        --words[i];
                }
                printf("\n");
        }
}