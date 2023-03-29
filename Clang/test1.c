#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myPrint(const char* arr);

int main() {
    myPrint("Hui tebe, a ne const char arr\n");
}

void myPrint(const char* arr) {
    fwrite(arr, sizeof(char), strlen(arr), stdout);
}