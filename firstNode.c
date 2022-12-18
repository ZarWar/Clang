#include <stdio.h>

typedef struct derevo {
    struct derevo *left;
    struct derevo *right;
    int number;
} node;

void addNumber (node A, int d);

int main() {
    node head;

    int c;
    for(int i = 0; i < 5; i++) {
        c = scanf("%d");
        if(i == 0){
            head.number = c;
        } else {
            addNumber(head, c);
        }
    }

    return 0;
}

void addNumber (node A, int d) {
    if(d > A.number) {
        A.right = (node *)calloc(1, sizeof(node));
        addNumber(A.right, d);
    } else if (d < A.number) {
        A.left  = (node *)calloc(1, sizeof(node));
        addNumber(A.left, d);
    }
    return;
}