#include <stdio.h>

#define LIMIT 1000
 
int main() {
    int sum=0, i=0;
    char val, arr[LIMIT]={0}, c;
    FILE *r = fopen("./feof_r.txt","r");

    if(!r) {
        printf("Error open .txt\n");
    } else {
        while( (c = fgetc(r)) != EOF) {
            arr[i]=c;
            printf("%d->%c__", i, arr[i]);
            i++;
            
        }
        fclose(r);
    }
    printf("Сейчас в массиве следующая строка:\n");
    for (int y=0; y<i; y++) {
        printf("%c", arr[y]);
    }
    printf("\n");

    FILE *w = fopen("./feof_w.txt","w");

    for(int u=0; u<i; u++) {
        fputc(arr[u], w);
    }    

    fclose(w);
    return 0;
}