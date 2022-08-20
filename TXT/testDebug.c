#include <stdio.h>
 
int main() {
    char str = 0;
    char nline = ' ';
    int n=0;
    FILE *f = fopen("./testFile.c","r+");
    if(!f) {
        printf("Error open .c\n");
    } else {
        while(!feof(f)) {
            if(fgets(&str, n ,f)) {
                printf("nline = '%c\n'", nline);
                if(nline == '\n') {
                    str++;
                }
            }
        }
    fclose(f);
    printf("%d\n", str);
    }
    return 0;
}