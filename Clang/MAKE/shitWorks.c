#include <stdio.h>

#define LIMIT 1000
 
int main() {
    int i=0,
        y=0,
        slash=0,
        slashSize=0,
        star=0,
        starSize=0,
        arrSize,
        indexN;
    char c, arrA[LIMIT]={'\0'}, arrB[LIMIT]={'\0'}, arrC[LIMIT]={'\0'}, arr[LIMIT]={'\0'};
    FILE *r = fopen("./shitWorks_r.txt","r");

    if (!r) {
        printf("Error open _r.txt\n");
    } else {
         for (i=0; (c=fgetc(r))!=EOF; i++) {
            arr[i] = c;
        }
        arrSize = i;
    }
    fclose(r);

    for (i=0; i<arrSize; i++) {
        if (arr[i] == '/' && arr[i+1] == '/') {
            slash = 1;
            indexN = i;
        } if (slash == 1 && arr[i] != '\n') {
            arrB[i] = arr[i];
        } else if (slash == 1 && arr[i] == '\n' && arr[indexN-1] == '\n') {
            slash = 0;
            arrB[i] = arr[i];
        } else if (slash == 1 && arr[i] == '\n' && arr[indexN-1] != '\n') {
            slash = 0;
            arrA[i] = '\n';
            arrB[i] = arr[i];
        } else {
            arrA[y] = arr[i];
            y++;
            // arrA[i] = arr[i];
            // с таким кодом "dfd" отделяется от "wert" новой строкой

        }
    }
    arrA[y+1] = '\0';
    slashSize = i;

    y = 0;
    for (i=0; i<arrSize-1; i++) {
        if (arrA[i] == '/' && arrA[i+1] == '*') {
            star = 1;
        }  if (star == 1 && arrA[i] == '*' && arrA[i+1] != '/') {
            arrB[i] = arrA[i];
        } if (star == 1 && arrA[i] == '/' && arrA[i+1] != '*') {
            arrB[i] = arrA[i];
        }
         if (star == 1 && arrA[i] != '*' && arrA[i+1] != '/') {
            arrB[i] = arrA[i];
            arrB[i+1] = arrA[i+1];
            i++;
        }  else if (star == 1 && arrA[i] == '*' && arrA[i+1] == '/') {
            star = 0;
            arrB[i] = arrA[i];
            arrB[i+1] = arrA[i+1];
            arrB[i+2] = '\n';
            i++;
            i++;
        } else if (star == 1 && arrA[i] == '*') {
            arrB[i] = arrA[i];
        } else {
            arrC[y] = arrA[i];
            y++;
        }
    }
    starSize = i;

    printf("\n'Исходная версия, считанная из файла:'\n\n");
    for (i=0; i<arrSize; i++) {
        printf("%c", arr[i]);
    }
    printf("\n\n");
    printf("'Обработанная версия, которая запишется в файл:'\n\n");
    for (i=0; i<arrSize; i++) {
        printf("%c", arrC[i]);
    }
    printf("\n\n\n");
    printf("'Вся вырезанная шляпа:'\n\n");
    for (i=0; i<arrSize; i++) {
        printf("%c", arrB[i]);
    }

    FILE *w = fopen("./shitWorks_w.txt","w");
    if (!w) {
        printf("Error open _w.txt\n");
    } else {
        i=0;
        while (arrC[i] != EOF && i<arrSize) { /* здесь поменять arrSize */
            fputc(arrC[i], w);
            i++;
        }
    }
    fclose(w);
    return 0;
}