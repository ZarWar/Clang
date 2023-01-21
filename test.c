#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree{
    int number;
    struct tree *left;
    struct tree *right;
} node;

int countAN = 1; // счетчик выполнения функции addNumber
int countPS = 1; // счетчик выполнения функции printStructure

void addNumber (node A, int d);
void printStructure(node A);
node createNote(void);

int main() {

    node A;

    int c = 2;

    while(c < 5) {
        scanf("%d", &c);
        addNumber(A, c);
    }

    printf("str 29: %d\n", A.right->number);
    printf("\n\n");

    printStructure(A);

    return 0;
}

void addNumber(node A, int d) {

    printf("str 39: countAN=%d\n", countAN);

    if(d > A.number || d == A.number) {

    printf("str 43: %lu\n", sizeof(A.right));

        if(sizeof(A.right) == 8) {
            countAN++;

            A.right  = (node *)calloc(1, sizeof(node));
            A.right->number = d;

            printf("str 51: %d\n", A.right->number);

            return;
        } else if (sizeof(A.right) == 24) {
            countAN++;

            printf("str 57\n");

            addNumber(*A.right, d);
        }
        
    }
    return;

}

void printStructure(node A) {

    printf("str 69: countPS=%d\n", countPS);
    printf("str 70\n");
    printf("str 71: %lu\n", sizeof(A.right));

    if(sizeof(A.right) == 24) {
        printf("str 74: %lu\n", sizeof(A.right));
        printf("str 75: %d\n", A.number);

        countPS++;

        printStructure(*A.right);
    } else {
        return;
    }

}

node createNote(void) {
    node A;
    A.number = 5;
    A.left = NULL;
    A.right = NULL;

    return A;
}