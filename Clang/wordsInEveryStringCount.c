#include <stdio.h>

#define LIMIT 1000
#define IN 1
#define OUT 0
 
int main() {
    int i=0, y=1, arrSize, words=0, state=OUT;
    char c, arr[LIMIT]={0};
    FILE *r = fopen("./test_r.txt","r");

    if (!r) {
        printf("Error open _r.txt\n");
    } else {
         for (i=0; (c=fgetc(r))!=EOF; i++) {
            arr[i] = c;
        }
        arrSize = i;
    }
    fclose(r);

    for (i=0; i<arrSize; i++) {
        if (arr[i] == ' ' || arr[i] == '\n' || arr[i] == '\t') {
            state = OUT;
        } if (arr[i] == '\n') {
            printf("Слов в строке №%d: %d\n", y, words);
            words=0, y++;
        }
        else if (state == OUT && arr[i] != ' ') {
            state = IN;
            words++;
        }
    }
}