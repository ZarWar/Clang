#include <stdio.h>

#define LIMIT 1000

char getl(char s[], int limit);
char revers(char s[], int size);

int main() {
    int c,i,r,v,nc;
    nc = 0;
    char s[LIMIT]={0};
    for (i=0; i<LIMIT-1 && (c=getchar() != '\n'); i++) {
        s[i] = c;
        nc++;
    }
    reverse(s[], LIMIT);
}

char getl(s[], int limit) {
    int c,i,r,v,nc;
    nc = 0;
    char s[LIMIT]={0};
    for (i=0; i<LIMIT-1 && (c=getchar() != '\n'); i++) {
        s[i] = c;
        nc++;
    }
    reverse(s[], LIMIT);
}

int reverse(char s[], int size) {
    int i,r;
    char revarr[size] = {0};

    for (r=0; r<size; r++) {
        revarr[(size-1)-r] = arr[r];
        if ((size/2)%2 != 0) {
            if (r==size/2) {
                revarr[r] = arr[r];
            }
        }
        printf("%d\n", revarr[(size-1)-r]);
    }
    // for (i=0; i<size; i++) {
    //     printf("%d", revarr[i]);
    // }
    return revarr;
}