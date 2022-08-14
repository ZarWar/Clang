#include <stdio.h>

int main() {
    char a[3][3] = {{'a','b','c'},
                    {'d','e','f'},
                    {'g','h','\0'}};
    printf("%s\n", a[1]);
    return 0;
}