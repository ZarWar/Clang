// strDebug.pl --file=polishCalc_v2_wStructArr.c && gcc -o ./polishCalc_v2_wStructArr_O ./polishCalc_v2_wStructArr.c && ./polishCalc_v2_wStructArr_O
// не начал ещё использовать MAKE-файл, поэтому оставляю себе закомментированными готовые команды
// на запуск проги

/*
    Обратный польский калькулятор.
    Цифры сохранятся в стеке. Математические операции производятся над
    последними двумя значениями стека.
    Пишем:
        5 2 4 *
    Получаем:
        Сохранили в стэк 5, 8
    После пишем:
        4 /
    Получаем:
        В стеке теперь хранится 5, 2

    Чтобы вывести на экран содержимое стека, пишем латиницей "P" (сокращенное от 'print')
    Также можно создавать переменные, и присваивать им заранее нужное значение.
    Например:
        a=-4
        b=3

    Когда вводим...
        a b * P
    ...получаем
        -12

    Вводим...
        2 5 P R - P    // перед последним 'P' знак "минус"
    ...получаем    
        Печать элементов стека:
            №0 = 2.000000
            №1 = 5.000000
        Печать элементов стека:
            №0 = 3.000000
*/

#include  <stdio.h>
#include  <ctype.h>
#include  <stdlib.h>
#include  <math.h>

/*
    константы используются в блоке switch{} на 97 строке.
    Когда мы их вводим, условие свитча проваливается в нужный блок, и отрабатывается функция.
*/

#define   LETTERS 10
#define   MAXOP 100
#define   MAXVAL 100
#define   BUFSIZE 100

#define   NUMBER '0' // константа для добавления чисел в стэк
#define   STRUCT 'T' // копирует последнюю созданную переменную из созданной для хранения переменных структуры, создаёт ещё одну пустую ячейку стэка выше, и вставляет в него скопированное значение
#define   HEAD 'H' // печатает верхнее значение стэка
#define   DUPLICATE 'D' // копирует верхнее значение стэка, создаёт ещё одну пустую ячейку стэка выше, и вставляет в него скопированное значение
#define   REPLACE 'R' // меняет местами верхнее значение стэка с предыдущим
#define   PRINT 'P' // выводит на печать все элементы стэка
#define   PRINTSTRUCT 'K' // выводит на печать сохранённые переменные. Чтобы сохранить переменную, нужно ввести: a=-5. Досупны буквы от 'a' до 'j'
#define   CLEAR 'C' // удаляет все элементы стэка
#define   POWER 'W' // предыдущее значение стэка возводится в степень по основанию верхнего значения стэка
#define   SINUS 'S' // синус))
 
char      c = ' '; 
int       sp = 0;
int       bufp = 0;
int       count = 0;
char      s           [MAXOP];
char      operators   [MAXOP];
char      operands    [MAXOP];
char      buf         [BUFSIZE];
double    val         [MAXVAL];
    
char      compare     (char c);
int       getop       (char[]);
int       getch       (void);
double    head        (void);
double    pop         (void);
void      ungetch     (int);
void      push        (double);
void      nline       (void);
void      clear       (void);
void      print       (void);
void      replace     (void);
void      power       (void);
void      printStruct (void);

struct    numberLetter {
          char    l;
          double  n;
          };
struct    numberLetter structArr[LETTERS] = {
          'a', '\0',
          'b', '\0',
          'c', '\0',
          'd', '\0',
          'e', '\0',
          'f', '\0',
          'g', '\0',
          'h', '\0',
          'i', '\0',
          'j', '\0'
          };

int main() {
    int type;
    double op1, op2, type2;
    while((type = getop(s)) != EOF) { 
        switch(type) {
        case NUMBER:
            push(atof(s));
            break;
        case STRUCT:
            push(structArr[count].n);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '%':
            op2 = pop();
            op1 = pop();
            if(op2 != 0.0) {
                int op3 = op1 / op2;
                double op4 = op1 - (op3 * op2);
                push(op4);
                break;
            } else {
                printf("ошибка: модуль от нуля %c\n", '%');
                break;
            }
        case '/':
            op2 = pop();
            if(op2 != 0.0) {
                push(pop() / op2);
                break;
            } else {
                pop();
                printf("ошибка: деление на нуль \\ \n");
                break;
            }
        case '=':
            break;
        case HEAD:
            printf("HEAD = %f\n", head());
            break;
        case DUPLICATE:
            push(head());
            break;
        case CLEAR:
            clear();
            break;
        case PRINT:
            print();
            break;
        case REPLACE:
            replace();
            break;
        case POWER:
            power();
            break;
        case SINUS:
            push(sin(pop()));
            break;
        case PRINTSTRUCT:
            printStruct();
            break;
        case '\n':
            break;
        
        default:
            printf("ошибка: неизвестная операция '%s'\n", s);
            break;
            return 0;
        }
    }
}

int getop(char s[]) {
    int i = 0;
    while((c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[0] = c;

    if(
        s[0] == HEAD ||
        s[0] == DUPLICATE ||
        s[0] == CLEAR ||
        s[0] == REPLACE
    ) {
        return s[0];
    }
    s[1] = '\0';

    i = 0;
    if(c == 'p' || c == 's') {
        while((s[++i] = c = getch()) != EOF) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                continue;
            } else {
                ungetch(c);
                break;
            }
        }
        if(s[0] == 'p' && s[1] == 'o' && s[2] == 'w') {
            return POWER;
        } else if (s[0] == 's' && s[1] == 'i' && s[2] == 'n') {
            return SINUS;
        }
    }

    i = 0;
    if(s[0] >= 'a' && s[0] <= 'j') {
        count = 0;
        for(i=0; i<LETTERS; i++) {
            count = i;
            if(s[0] == structArr[i].l) {
                break;
            }
        }
        if ((c=getch()) == '=') {
            s[1] = c;
            if(s[0] >= 'a' && s[0] <= 'j' && s[1] == '=') {
                int i = 0;
                while((c = getch()) == ' ' || c == '\t') {
                    ;
                }

                if(!isdigit(c) && c != '.' && c != '-')
                    ;

                if(c == '-') {
                    for(int i=0; i<10; i++) {
                        s[i] = '\0';
                    }
                    i = 0;
                    while(isdigit(s[i++] = c) != EOF) {
                        c = getch();
                        if(c == '\n') {
                            s[i] = '\0';
                            structArr[count].n = atof(s);
                            break;
                        }
                    }
                }

                if(isdigit(c)) {
                    for(int i=0; i<10; i++) {
                        s[i] = '\0';
                    }
                    i = 0;
                    while(isdigit(s[i++] = c) != EOF) {
                        c = getch();
                        if(c == '\n') {
                            s[i] = '\0';
                            structArr[count].n = atof(s);
                            break;
                        }
                    }
                }
            }
        } else if (c != '=') {
            return STRUCT;
        }
    }

    if(!isdigit(c) && c != '.' && c != '-')
        return c;

    i = 0;
    if(c == '-') {
        while(isdigit(s[++i] = c = getch()));
        if(i == 1) {
            ungetch(c);
            return '-';
        }
    }

    if(isdigit(c)) {
        while(isdigit(s[++i] = c = getch()))
            ;
    }

    if(c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    
    if(c != EOF)
        ungetch(c);

    return NUMBER;
}

int getch(void) {
    return(bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c) {
    if(bufp >= BUFSIZE)
        printf("ungetch: слишком много символов\n");
    else
        buf[bufp++] = c;
}

double pop(void) {
    if(sp > 0) {
        return val[--sp];
    } else {
        printf("ошибка: стек пуст\n");
        return 0.0;
    }
}

void push(double f) {
    if(sp < MAXVAL) {
        val[sp++]=f;
    } else {
        printf("ошибка: стек полон, %g не помещается\n", f);
    }
}

void nline(void) {
    printf("\t%.8g\n", head());
}

double head(void) {
    return val[sp-1];
}

void clear(void) {
    sp = 0;
    val[0] = '\0';
}

void print(void) {
    if (val[0] == '\0') {
        printf("    print() error: стек пуст\n");
    } else {
        printf("Печать элементов стека:\n");
        for (int i=0; i<sp; i++) {
            printf("    №%d = %f\n", i, val[i]);
        }
    }
}

void printStruct(void) {
    printf("printStruct(): вывод всех элементов массива структур\n");
    for(int i=0; i<LETTERS; i++) {
        printf("   sA[i].l='%c', sA[i].n='%g',\n", structArr[i].l, structArr[i].n);
    }
}

void replace(void) {
    double temp = val[sp-1];
    val[sp-1] = val[sp-2];
    val[sp-2] = temp;
}

void power(void) {
    double op2 = pop();
    double op1 = pop();
    double temp = op1;

    for(int i=1; i<op2; i++) {
        op1 *= temp;
    }
    push(op1);
}

char compare (char c) {
    if(c>='a' && c<='j') {
        return c;
    } else {
        return 0;
    }
}