#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct tree{
    int number;
    struct tree *left;
    struct tree *right;
    char leftExists;
    char rightExists;
    char numberExists;
} node;

node* addStructure();
void addRight(node* A);
void addLeft(node* A);
void addNumber(node *A ,int d);
void printNode(node *A, int s);

int main () {
    node *A = addStructure();

    int d;
    for(int i = 0; i < 7; i++) {
        scanf("%d", &d);
        addNumber(A, d);
    }

    printf("\n\n");

    printNode(A, 0);

    return 0;
}

node* addStructure() {
    node* A = (node *)calloc(1, sizeof(node));

    A->leftExists = FALSE;
    A->rightExists = FALSE;
    A->numberExists = FALSE;

    return A;
}

void addRight(node* A) {
    A->rightExists = TRUE;
    A->right = addStructure();
}

void addLeft(node* A) {
    A->leftExists = TRUE;
    A->left = addStructure();
}

void addNumber(node *A ,int d) {
    if (A->numberExists == TRUE && d < A->number && A->leftExists == TRUE) {
        addNumber(A->left, d);
    } else if (A->numberExists == TRUE && d > A->number && A->rightExists == TRUE) {
        addNumber(A->right, d);
    } else if (A->numberExists == TRUE && d < A->number && A->leftExists == FALSE) {
        addLeft(A);
        addNumber(A->left, d);
    } else if (A->numberExists == TRUE && d > A->number && A->rightExists == FALSE) {
        addRight(A);
        addNumber(A->right, d);
    } else {
        A->number = d;
        A->numberExists = TRUE;
    }
}

void printNode(node *A, int s) {
    if (A->numberExists == TRUE && s == 0) {
        for (int i = 0; i < s; i++) {
            printf(" ");
        }
        printf("%d\n", A->number);
    }

    
    if (A->leftExists == TRUE && A->left->numberExists == TRUE) {
        for (int i = 0; i < s + 1; i++) {
            printf(" ");
        }
        printf("%d\n", A->left->number);
    }

    if (A->rightExists == TRUE && A->right->numberExists == TRUE) {
        for (int i = 0; i < s + 1; i++) {
            printf(" ");
        }
        printf("%d\n", A->right->number);
    }

    s++;
    
    if (A->leftExists == TRUE) {
        printNode(A->left, s);
    }

    if (A->rightExists == TRUE) {
        printNode(A->right, s);
    }
}