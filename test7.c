#include <stdio.h>
 
int main() {
    FILE *f = fopen("./input.txt","r+");
        int a, b;
        fscanf(f,"%d %d", &a, &b);	
        fclose(f);
        
        FILE *w = fopen("./output.txt","w");
        fprintf(w,"%d\n", a + b);
        fclose(w);
    return 0;
}