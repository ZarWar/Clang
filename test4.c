#include <stdio.h>

#define MAXOP 100

char s[MAXOP];

int getop(void);
int getopStruct(char s[]);
int mainStruct(char s[]);

int main() {
    int type;
    double op1, op2, type2;
    while((type = getop(s)) != EOF) {

    }

    return 0;
}

int getop(void) {
    char c = getchar();
    return c;
}

int getopStruct(char s[]);
int mainStruct(char s[]);