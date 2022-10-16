#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 4

int main() {
    char a[10] = {'a','b','c','\0','r','y','\0'};
    int b = strlen(a);
    printf("%d\n", b);
}