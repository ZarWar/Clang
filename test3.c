#include <stdio.h>

#define ASCII 128

int main() {
    int c;
    for (int i=0; i<ASCII; i++) {
        printf("%d> %c\n", i, i);
    }
}