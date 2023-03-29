#include <stdio.h>

#define SIZE 5

int strlength(char *arr);

int main() {
    int i;
    char s[SIZE] = {'h','e','l','l','o'};
    printf("%d\n", strlength(s));

    return 0;
}

int strlength(char *arr) {
    int sl;
    for (sl=0; *arr!='\0'; arr++) {
        sl++;
    }
    return sl;
}