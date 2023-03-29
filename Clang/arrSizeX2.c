#include <stdio.h>
#include <stdlib.h>

#define N 10

int* doubleCapacity(int *arr,  int size) {
    int i, n;
    int *r=(int*)realloc(arr, size * 2 * sizeof(int));
    if(r==NULL)return NULL;
    for (i=size, n=size*2; i<n; i++) r[i]=0;
    free(arr);
    return r;
}
 
int main(void) {
    int i;
    int* m=(int*)malloc(sizeof(int)*N); 
    for (i=0; i<N; i++) m[i]=i; 
    for (i=0; i<N; i++) printf("%d ",m[i]);
    puts("");
    m=doubleCapacity(m,N);
    if(m!=NULL)
    { 
        for (i=0; i<N*2; i++) printf("%d ",m[i]);
        puts("");
    }
    else 
        printf("error!");
    free(m); 
 
    return 0;
}