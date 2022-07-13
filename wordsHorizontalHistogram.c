#include <stdio.h>

#define IN 1
#define OUT 0

int main() {

    int c, i, y, p, b, nword, state, lenw;
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
            
            for (i=9; i>=0; i--) {
                printf("\n");
                for (y=0; y<10; y++) {
                    if (i>=words[y]) {
                        printf("  ");
                    } else {
                    printf(" -");
                    }
                }
            }
            printf("\n");
            for (i=0; i<10; i++) {
            printf("|%d", i);
            }
            printf("\n");
            printf("Количество слов: %d\n", nword);
            printf(":Горизонтальная гистограмма длин слов:\n");
      
        }
        
    }
    
    return 0;

}