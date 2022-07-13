#include <stdio.h>

int main() {
    int a,b, temp;
    a = 1;
    b = 2;
    
    temp = b;
    b = a;
    a = temp;
    printf("a=%d, b=%d", a, b);
}