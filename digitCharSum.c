#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char intToChar     (int digit);
int  charToInt     (char digit);
char shift         (char *arr);
char reverseString (char *arr);

int ostatok = 0;

int main() {
    int H = 3;
    int W = 4;
    int n = 0;
    
    int biggest;
    int smaller;

    int temp1Reg;
    int temp2Reg;
    int tempDigit;

    char **A = (char **)calloc(H, sizeof(char *));

    for(int i=0; i<H; i++) {
        A[i] = (char *)calloc(W, sizeof(char));
    }

    char c;
    int i = 1;
    int y = 0;
    while((c = getchar()) != EOF) {
        if(i == W - 1) {
            W *= 2;
            A[y] = (char *)realloc(A[y], W * sizeof(char));
        }
        
        if(c == '\n') {
            n++;
            if (n == 2) {
                A[0][0] = '.'; // здесь мне нужен нулевой индекс, не забитый '\0'
                A[1][0] = '.'; // здесь мне нужен нулевой индекс, не забитый '\0'
                break;
            }
            y++;
            i = 1;
        } else {
            A[y][i++] = c;
        }
    }

    printf("\n");
    printf("A[0]    = '%s'\n", A[0]);
    printf("A[1]    = '%s'\n", A[1]);

    // здесь сравниваю длину массива#2 с массивом#1, и сохраняю результат в две разные переменные
    if(strlen(A[y]) > strlen(A[y-1])) {
        biggest = strlen(A[y]) - 1;
        smaller = strlen(A[y-1]) - 1;
    } else {
        biggest = strlen(A[y-1]) - 1;
        smaller = strlen(A[y]) - 1;
    }

    printf("biggest = '%d'\n", biggest);
    printf("smaller = '%d'\n", smaller);
    printf("\n");

    /* Забиваю результирующий массив "точками" для лучшей наглядности работы проги */
    for(int i = biggest-1; i >= 0; i--) {
        A[2][i] = '.';
    }

    for(int i = biggest; i >= 1; i--) {
        /* этим if() я подстраиваю подсчёт под массив, что покороче.
        визуализирую логику, как будто считаю в столбик:
        125+    делаю как    125+ 
        5                      5  
        сдвигаю "5" за счёт переменной "smaller" */ 
        if(strlen(A[y-1]) > strlen(A[y])) {
            if(ostatok > 0) {
                printf("str 83:  i = '%d'\n", i);
                tempDigit = charToInt(A[0][i]) + charToInt(A[1][(smaller--)]) + ostatok; // делаю тут "[(smaller--)-1]" для правильной индексации
            }
            if (ostatok == 0) {
                printf("str 87:  i = '%d'\n", i);
                tempDigit = charToInt(A[0][i]) + charToInt(A[1][(smaller--)]); // делаю тут "[(smaller--)-1]" для правильной индексации
            }
        } else if(strlen(A[y-1]) < strlen(A[y])) {
            if(ostatok > 0) {
                printf("str 92:  i = '%d'\n", i);
                tempDigit = charToInt(A[1][i]) + charToInt(A[0][(smaller--)]) + ostatok; // делаю тут "[(smaller--)-1]" для правильной индексации
            }
            if (ostatok == 0) {
                printf("str 96:  i = '%d'\n", i);                
                tempDigit = charToInt(A[1][i]) + charToInt(A[0][(smaller--)]); // делаю тут "[(smaller--)-1]" для правильной индексации
            }
        } else if(strlen(A[y-1]) == strlen(A[y])) {
            if(ostatok > 0) {
                printf("str 101:  i = '%d'\n", i);                
                tempDigit = charToInt(A[1][i]) + charToInt(A[0][(smaller--)]) + ostatok; // делаю тут "[(smaller--)-1]" для правильной индексации
            }
            if (ostatok == 0) {
                printf("str 105:  i = '%d'\n", i);                
                tempDigit = charToInt(A[1][i]) + charToInt(A[0][(smaller--)]); // делаю тут "[(smaller--)-1]" для правильной индексации
            }
        }
        
        if(tempDigit > 9) {
            temp2Reg = tempDigit / 10;
            temp1Reg = tempDigit % 10;
        } else {
            temp1Reg = tempDigit;
            temp2Reg = 0;
        }

        if (temp2Reg > 0) {
            ostatok = temp2Reg;
        } else {
            ostatok = 0;
        }

        printf("str 124: tempDigit = '%d'\n", tempDigit);
        printf("str 125: temp1Reg  = '%d'\n", temp1Reg);
        printf("str 126: ostatok   = '%d'\n", ostatok);

        A[2][i] = intToChar(temp1Reg);

        if(i == 1 && ostatok != 0) {
            A[2][0] = intToChar(ostatok);
        } else if (i == 1 && ostatok == 0) {
            shift(A[2]);
        }
        
        printf("check summa        = '%s'\n", A[2]);
        printf("\n");
    }

    printf("summa = %s\n", A[2]);

    return 0;
}

char intToChar (int digit) {
    if(digit >= 0 && digit <= 9) {
        return digit + 48;        
    }
    return 0;
}

int charToInt (char digit) {
    if(digit >= '0' && digit <= '9') {
        return digit - 48;        
    }
    return 0;
}

char shift(char *arr) {
    int lenght = strlen(arr);
    for(int i = 1; i < lenght; i++) {
        arr[i - 1] = arr[i];
    }
    arr[lenght - 1] = '\0';
    
    return *arr;
}

/* мне функция "reverseString()" уже не нужна, но пусть пока тут останется.
Планировал разворачивать массив на моменте суммирования элементов первого и второго массива.
Но понял, что могу оставить неиспользованным нулевой индекс массива, и если есть остаток от суммирования,
то переношу его в этот нулевой индекс. Нету остатка - двигаю массив на один элемент влево функцией shift().
Тоесть я только единожды двигаю массив целиком, в отличии от использования функции reverseString(),
которую бы пришлось использовать дважды */
char reverseString(char *arr) {
    int temp;
    int lenght = strlen(arr)-1;
    printf("%d\n", lenght);
    for(int i = 0; i < lenght/2; i++) {
        temp = arr[i];
        arr[i] = arr[lenght];
        arr[lenght--] = temp;
    }
    return *arr;
}