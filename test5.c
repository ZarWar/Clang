#include <stdio.h>

#define LETTERS 2
#define ONELETTER 1
#define DIGITS 100

int main() {
    struct nl {
        char l;
        double n;
    };

    struct nl structArr[] = {'a', 222, 'b', 456, 'c', 789};

    printf("staructArr[0].l='%c'\n", structArr[0].l);
    printf("staructArr[0].n='%g'\n", structArr[0].n);

    printf("staructArr[0].n='%c'\n", structArr->l);

    return 0;
}