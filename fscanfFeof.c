#include <stdio.h>

#define LIMIT 1000
 
int main() {
    int sum=0, i=0;
    char val, arr[LIMIT]={0};
    FILE *r = fopen("./TXT/fscanfFeof_r.txt","r");
    FILE *w = fopen("./TXT/fscanfFeof_w.txt","w");

    if(!r) {
        printf("Error open _r.txt\n");
    } else if (!w) {
        printf("Error open _w.txt\n");
    } else {
        while(!feof(r)) {
            if(fscanf(r,"%c",&val)) {
                arr[i]=val;
                fputc(arr[i], w);
                i++;
            }
        }
        fclose(r) && fclose(w);
    }

    return 0;
}