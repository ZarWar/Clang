#include <stdio.h>

char c, nc, sp = 0;
int n = '\n';
int spaces[100];

int main() 
{
   while (c != EOF) {
      c = getchar();

      if (c == ' ') {
         c = '\n';
      }

      if (c == '\n' || c == ' ') {
         nc++;
         if (c == '\n') {
            printf("\t(%d -строк)", nc);
         } 
      }

      if (nc == 10) { // завершение после 10'ой строки
         return 0;
      } else {
         ;
      }

      putchar(c);
   }
   
}