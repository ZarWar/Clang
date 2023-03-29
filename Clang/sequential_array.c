#include <stdio.h>

int main() {
	int digit[10];
	int i, j;
	for (i=0; i<10; i++) {
		digit[i] = 0;
	}
	for (j=0; j<10; j++) {
		digit[j] = digit[j-1]+1;
		printf("%d\n", digit[j]);
	}
}