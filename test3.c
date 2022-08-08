#include <stdio.h>

int main() {
    struct Vector {
        int x;
        int y;
    };

    struct Vector v = {9,4};

    printf("%d\n", v.x * v.y);
}