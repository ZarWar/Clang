#include <stdio.h>

int main (void) {  
   // Переменная, в которую будет помещен указатель на созданный
   // поток данных 
   FILE *mf;

   // Код символа s
   int sym=115;

   // Переменная, в которую будет помещено возвращаемое функцией
   // fputc значение.
   int esym=-1;
    
   // Открытие файла с режимом доступа «запись» и привязка к нему
   // потока данных
   printf("Open file: ");
   mf = fopen ("./TXT/exFputc.txt","r+");

   if (mf == NULL) {
       printf ("error\n"); 
       return -1;
    } else {
        printf("done\n");
    }
   printf ("Запись в файл: ");

   // Запись символа в файл
   esym = fputc(sym, mf);

   // Проверка записи
   if (esym == EOF)
      printf ("ошибка записи\n");
   else 
      printf ("записан символ '%c'\n",esym);

   // Закрываем файл
   printf ("Закрытие файла: ");
   if ( fclose (mf) == EOF) printf ("error\n");
   else printf ("done\n");

   return 0;
} 