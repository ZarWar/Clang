#include <stdio.h>
 
int main() {
    char val;
    int sym=115;
    int esym=-1;
    FILE *f = fopen("./TXT/exFputc.txt","r+");
    if(!f) {
        printf("Error open .txt\n");
    } else {
        while(!feof(f)) {
            for(int i=0; i<2; i++) {
                if(fscanf(f,"%c\n",&val)) {
                    if(val == 'd') {
                        fputc(sym, f);
                    }
                }
            }
        }
        fclose(f);
    }
    return 0;
}