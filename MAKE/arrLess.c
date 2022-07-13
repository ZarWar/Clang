#include <stdio.h>

int main() {
    int i = 0;
    char c,
         pch = '\0';

    FILE *r = fopen("./arrLess_r.txt","r");
    FILE *w = fopen("./arrLess_w.txt","w");


    if (!r) {
        printf("Error open _r.txt\n");
    } 
    while ((c=fgetc(r)) != EOF) {
        if (c == '/' && pch == '/') {
            pch = '\0';
            while ((c=fgetc(r)) != EOF) {
                fputc(c, w);
                if (c == '\n') {
                    break;
                }
            }
        }
        else if (c == '*' && pch == '/') {
            while ((c=fgetc(r)) != EOF) {
                if (c == '/' && pch == '*') {
                    break;
                } else if (c == '*') {
                    pch = c;
                } else if (c != '/' && pch == '*') {
                    fputc(pch, w);
                    fputc(c, w);
                    pch = c;
                } else {
                    fputc(c, w);
                    pch = c;
                } 
            }
        }
        pch = c;
    }

    fclose(r);
    fclose(w);
    return 0;
}