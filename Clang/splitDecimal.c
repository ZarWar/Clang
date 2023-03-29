#include <stdio.h>
#include <string.h>

int main() {

int digit3 = 5;
int temp1;
int temp2;
int ostatok;

    if(digit3 % 10 != 0) {
        temp2 = digit3 / 10;
        temp1 = digit3 % 10;
    }

    if (temp2 != 0) {
        ostatok = temp2;
    } else {
        ostatok = 0;
    }

    printf("temp2 = '%d'\n", ostatok);
    printf("temp1 = '%d'\n", temp1);
}