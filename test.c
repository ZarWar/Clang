#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

#define HEAD 'H'
#define DUPLICATE 'D'
#define CLEAR 'C'
#define REPLACE 'R'
#define PRINT 'P'
#define PRINTOP 'O'
#define POWER 'W'
#define SINUS 'S'

int    sp = 0;
int    spOp = 0;
int    bufp = 0;
char   s[MAXOP];
char   afterEquals[MAXOP];

char   buf[BUFSIZE];
double val[MAXVAL];
char     operands[MAXVAL];
double   operators[MAXVAL];

int    getop(char[]);
int      getch(void);
void     ungetch(int);
double     pop(void);
void       push(double);
double     popOp(void);
void       pushOp(char);
void        nline(void);
double      head(void);
void        clear(void);
void        print(void);
void        printOp(void);
void        replace(void);
void    power(void);
void    equals(void);

int main() {
    int type;
    double op1, op2, op4, type2;
    char op3;
    while((type = getop(s)) != EOF) { 
        switch(type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            pushOp('+');
            break;
        case '*':
            pushOp('*');
            break;
        case '-':
            pushOp('-');
            break;
        case '%':
            pushOp('%');
            break;
        case '/':
            pushOp('/');
            break;
        case HEAD:
            while(spOp > 0) {
                op1 = pop();
                op2 = pop();
                op3 = popOp();

                switch(op3) {
                case '-':
                    push(op2 - op1);
                    break;
                case '+':
                    push(op1 + op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op2 / op1);
                    break;
                case '=':
                    pushOp('=');
                    break;
                }
            }
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
        case PRINTOP:
            printOp();
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
        case '=':
            pushOp('=');
            break;
        case '\n':
            break;

        default:
            printf("ошибка: неизвестная операция %s\n", s);
            break;
            return 0;
        }
    }
}

int getop(char s[]) {
    int i, c; /* отсюда и до 135 строки мы отделяем стартовые лишние пробелы, и ждём введения непробельного символа */
    c = ' ';
    while(c == ' ' || c == '\t') {
        c = getch();
    }
    s[0]=c; /* как только мы ввели непробельный символ, сохранили его в символьный массив, чтобы в дальнейшем с ним работать */
    
    if( /* этот и дальнейшие 'ифы' по s[0] обрабатывают особые условия первого символа в символьном массиве s[] */ 
        s[0] == HEAD ||
        s[0] == DUPLICATE ||
        s[0] == CLEAR ||
        s[0] == REPLACE
    ) {
        return s[0];
    }

    if(s[0] >= 'a' && s[0] <= 'j') {
        while((c=getch()) == ' ' || (c=getch()) == '\t') { /* 'while' для хераченья сколько угодно пробелов между символом '=' и числами в момент присвоения переменной значения */
            ;
        }
        if ((c=getch()) == '=') {
            return c;
            c;
        } else {
            s[1] = '\0';
            i = 0;
            if(isdigit(c)) {
                while(isdigit(afterEquals[++i] = c = getch()) != EOF)
                    ;
                printf("строка 161: ")
            }
        }
    }

    s[1] = '\0';

    i = 0;
    if(c == 'p' || c == 's') {
        while((s[++i] = c = getch()) != EOF) {
            if(s[i] > 'a' && s[i] < 'z') {
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

double popOp(void) {
    if(spOp > 0) {
        return operands[--spOp];
    } else {
        printf("ошибка: стек пуст\n");
        return 0.0;
    }
}

void pushOp(char fOp) {
    if(spOp < MAXVAL) {
        operands[spOp++]=fOp;
    } else {
        printf("ошибка: стек полон, %c не помещается\n", fOp);
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

void printOp(void) {
    if (operators[0] == '\0') {
        printf("    printOp() error: стек пуст\n");
    } else {
        printf("Печать элементов стека:\n");
        for (int i=0; i<spOp; i++) {
            printf("    №%d = %f\n", i, operators[i]);
        }
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

void equals(void) {
    int type;
    while((type = getop(afterEquals)) != EOF) {
        switch(type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            pushOp('+');
            break;
        case '*':
            pushOp('*');
            break;
        case '-':
            pushOp('-');
            break;
        case '%':
            pushOp('%');
            break;
        case '/':
            pushOp('/');
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
        case PRINTOP:
            printOp();
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
        case '=':
            pushOp('=');
            break;
        case '\n':
            break;

        default:
            printf("ошибка: неизвестная операция %s\n", s);
            break;
            return 0;
        }
    }
}