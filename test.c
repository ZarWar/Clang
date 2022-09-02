#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *x = (char*) malloc(1);
    char *y = (char*) calloc(1, sizeof(char));
    char c = getchar();
    *y = c;
    printf("%d\n", *y);
}