#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
int bufp = 0;
char buf[BUFSIZE];
double val[MAXVAL];

int getop(char[]);
int getch(void);
void ungetch(int);
void push(double);
double pop(void);

// int main() {
//     double op1 = 6;
//     double op2 = 5;
//     double op3 =(op1 - op2)*(op1 / op2);

//     printf("%g", op3);
// }


int main() {
    int type;
    double op1, op2;
    char s[MAXOP];
    while((type = getop(s)) != EOF) { 
        switch(type) {
        case NUMBER:
            push(atof(s));
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
        case '%': /* сюда добавил возможность считать модуль числа */
            op2 = pop();
            if(op2 != 0.0) {
                op1 = pop();
                int op3 = op1 / op2;
                double op4 = op1 -(op3 * op2);
                push(op4);
                break;
            } else {
                printf("ошибка: деление на нуль\n");
                break;
            }
        case '/':
            op2 = pop();
            if(op2 != 0.0)
                push(pop() / op2);
            else
                printf("ошибка: деление на нуль\n");
                break;
        case '\n': 
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("ошибка: неизвестная операция %s\n", s);break;
            return 0;
        }
    }
}

double pop(void) {
    if(sp > 0)
        return val[--sp];
    else {
        printf("ошибка: стек пуст\n");
        return 0.0;
    }
}

void push(double f) {
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("ошибка: стек полон, %g не помещается\n", f);
}

int getop(char s[]) {
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;   
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;
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