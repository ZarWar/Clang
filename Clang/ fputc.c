#include < stdio.h >  //Для printf, fputc, fopen, fclose

int main (void)
{  
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
   printf (“Открытие файла: ”);
   mf = fopen (“./TXT/fputc.txt”,”r+”);

   // Проверка открытия файла
   if (mf == NULL) {printf (“ошибка\n”); return -1;}
   else printf (“выполнено\n”);

   printf (“Запись в файл: ”);
   // Запись символа в файл
   esym = fputc (sym, mf);

   // Проверка записи
   if (esym == EOF)
      printf (“ошибка записи\n”);
   else 
      printf (“записан символ '%c'\n”,esym);

   // Закрываем файл
   printf (“Закрытие файла: ”);
   if ( fclose (mf) == EOF) printf (“ошибка\n”);
   else printf (“выполнено\n”);

   return 0;
} 