#include <stdio.h>

int main() {
    int a = 1;
    int b = 8;

    do a += a, printf("%d", a);
    while (a<b);
}