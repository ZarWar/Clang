#include <stdio.h>
 
int main() {
    int sum = 0;
    char val;
    FILE *f = fopen("./TXT/string.txt","r+");
    if(!f) {
        printf("Error open .txt\n");
    } else {
        while(!feof(f)) {
            if(fscanf(f,"%c\n",&val)) {
                if(val == 'd') {
                    sum += 1;
                }
            }
        }
        fclose(f);
        printf("sum of 'd' char: %d\n",sum);
    }
    return 0;
}