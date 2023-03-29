#include <stdio.h>
 
int main() {
    int val, sum = 0;
    FILE *f = fopen("./TXT/sumNegativeFopen.txt","r");
    if(!f) {
        printf("Error open .txt\n");
    } else {
        while(!feof(f)) {
            if(fscanf(f,"%d\n",&val)) {
                if(val < 0) {
                    sum += val;
                }
            }    
        }
        fclose(f);
        printf("Sum of negative: %d\n",sum);
    }
    return 0;
}