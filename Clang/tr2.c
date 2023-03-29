#include <stdio.h>
#define MAXLINE 100

void reverse(char from[], int i);

int main(){
	int i, c;
	char line[MAXLINE];

	for(i=0; i<MAXLINE-1 && (c=getchar()) && c != EOF && c != '\n'; i++) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = '\0';
		reverse(line, i);
	}

	// printf("%s %d\n", line, i);
}

void reverse(char from[], int count) {
	for (int i=count-1; i>=0; i--) {
		putchar(from[i]);
	}
	putchar('\n');
}
