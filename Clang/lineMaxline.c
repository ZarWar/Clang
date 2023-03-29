#include <stdio.h>

#define LIMIT 1000

int getl(char arr[], int lim);
void copy(char to[], char from[]);

int main() {

    int len, max;
    char line[LIMIT];
    char longest[LIMIT];

    while ((len = getl(line, LIMIT)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
        if (max > 0) {
            printf("%s\n", longest);
        }
    }

}

int getl(char arr[], int lim) {

    int i,c;

    for (i=0; i<lim-1 && (c = getchar()) && c != '\n'; ++i) {
        arr[i]=c;
    }
    arr[i]='\0';
    return i;

}

void copy(char to[], char from[]) {

    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }

}