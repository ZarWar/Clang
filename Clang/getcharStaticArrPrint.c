#include <stdio.h>

int main() {
    int c,i;
    int limit = 20;
    char arr[20]={0};

    for (i=0; i<limit && (c=getchar()); i++) {
        arr[i]=c;
        if (c == ' ' || c == '\t') {
            arr[i]='_';
        } else if (c == '\n') {
            arr[i]='\0';
            i=-1;
            printf("%s\n", arr);
        }
    }
}