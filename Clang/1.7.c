#include <stdio.h>
int power(int m, int n);

/* тест функции power */
int main() {
        int i;
        for (i = 0; i < 10; ++i)
                printf("%d %d\n", i, power(-3, i));
        return 0;
}

/* возводит base в п-ю степень; n >= 0 */
int power(int base, int n) {
        int i, p;
        p = 1;
        for (i = 1; i <= n; ++i)
                p = p * base;
        return p;
}