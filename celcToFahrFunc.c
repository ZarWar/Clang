#include <stdio.h>

int CtoF (int cels);
int FtoC (int fahr);

int main() {
    
    int c;

    while (c != EOF) {
        c = getchar();
        CtoF(c);
        putchar(c);
    }

}

int CtoF (int cels) {
    int fahr = (cels * (9/5)) + 32;
    return fahr;
}