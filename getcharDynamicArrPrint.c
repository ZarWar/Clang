#include <stdio.h>
#include <stdlib.h>

#define LIMIT 100

int main() {

    int c,i,n,sp;
    n = sp = 0;
    char arr[LIMIT]={0};

    for (i=0; i<LIMIT-1 && (c=getchar()); i++) {
        arr[i]=c;
        if (c == '\n' || c == ' ' || c == '\t') {
            arr[i]='_';
        } else if (c == 'p') {
            if (c == 'p') {
                sp++;
                c = n;
            } else if (sp>0) {
                printf("p");
                sp=0;
            }
            arr[i]=' ';
            arr[i-1]=' ';
            --i;
            --i;
            printf("%s\n", arr);
        }
    }
    arr[i]='\0';
    printf("%s\n", arr);

}