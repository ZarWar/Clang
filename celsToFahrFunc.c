#include <stdio.h>

#define IN 1
#define OUT 0

int CtoF (int cels);
int FtoC (int fahr);

int main() {
    
    int c, i, state;
    state = IN;
    char digits[10];

    int cels = 15;
    printf("fahr %d\n", CtoF(cels));

    while (c != EOF) {

        c = getchar();
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
        } else if (state == OUT) {
            for (i=0; i<10; i++) {
                digits[i]=c;
            state = IN;
        }
        

        if (c == '\n') {
            
                printf("digits[%d]: ", digits[i]);
            }
            printf("\nfahr %d\n", CtoF(cels));
        }

    }

}

int CtoF (int cels) {
    int fahr = (cels * 1.8) + 32;
    return fahr;
}