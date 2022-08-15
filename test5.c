#include <stdio.h>

#define LETTERS 10

int main() {
    struct nl {
        char l[LETTERS];
        int  n[100];
    };

    int aLetter = 97;

    struct nl letterNumber;
    for(int i=0; i<LETTERS; i++) {
        letterNumber.l[i] = aLetter++;
        printf("l[i]='%c'\n", letterNumber.l[i]);
    }


    return 0;
}