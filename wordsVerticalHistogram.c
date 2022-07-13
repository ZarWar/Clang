#include <stdio.h>

#define IN 1
#define OUT 0

int main() {

    int c, i, p, b, nword, state, lenw;
    c = i = nword = lenw = 0;
    state = OUT;

    int words[10];
    for (i=0; i<10; i++) {
        words[i] = 0;
    }

    while (c != EOF) {
        c = getchar();

        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nword;
        }

        if (c == ' ' || c == '\t' || c == '\n') {
            ++words[lenw];
            lenw=0;
        } else {
            ++lenw;
        }

        if (c =='\n') {
            printf("Количество слов: %d\n", nword);
            printf("Гистограмма длин слов:\n");
            for (p=1; p<10; p++) {
                printf("%d: %d ", p, words[p]);
                for (b=0; b<words[p]; b++) {
                    printf("|");
                }
                printf("\n");
            }
            printf("\n");
        }
      
    }
    
    return 0;

}