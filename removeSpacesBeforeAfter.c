#include <stdio.h>

#define LIMIT 100

int main() {
    int i, y, b, d, sp, nc;
    char c;
    int n = 0;
    sp = 0;
    char arr[LIMIT] = {0};

    for (i=0; i<LIMIT-1 && (c=getchar()); i++) {
        arr[i] = c;

        if (c == '\n') {
            arr[i] = '\0';
            
            for (y=0; y<LIMIT-2; y++) {
                if (arr[y] == ' ' && arr[y+1] == ' ' || arr[y] == '\t' && arr[y+1] == '\t'
                || arr[y] == ' ' && arr[y+1] == '\t' || arr[y] == '\t' && arr[y+1] == ' ' 
                || arr[y] == '\a' && arr[y+1] == ' ' || arr[y] == '\a' && arr[y+1] == '\t'
                || arr[y] == ' ' && arr[y+1] == '\a' || arr[y] == '\t' && arr[y+1] == '\a') {
                    arr[y] = '\a';
                }
            }
            
            while (arr[n] == ' ' || arr[n] == '\t' || arr[n] == '\a') {
                printf("%c", arr[n]);
                arr[n] = '\a';
                n++;
            }

            if (arr[i-1] == ' ') {
                arr[i-1] = '\a';
            }


            printf("%s\\n\n", arr);
            
            i = -1;
        }
    }
}