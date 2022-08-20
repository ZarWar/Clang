#include  <stdio.h>
#include  <ctype.h>
#include  <stdlib.h>
#include  <math.h>
  
#define   MAXOP 100
#define   NUMBER '0'
#define   MAXVAL 100
#define   BUFSIZE 100
 
#define   HEAD 'H'
#define   DUPLICATE 'D'
#define   REPLACE 'R'
#define   PRINT 'P'
#define   CLEAR 'C'
#define   POWER 'W'
#define   SINUS 'S'
 
int       sp = 0;
int       bufp = 0;
char      s[MAXOP];
char      buf[BUFSIZE];
double    val[MAXVAL];
   
int       getop(char[]);
int       getch(void);
double    head(void);
double    pop(void);
void      ungetch(int);
void      push(double);
void      nline(void);
void      clear(void);
void      print(void);
void      replace(void);
void      power(void);


int main() {
    int type;
    double op1, op2, type2;
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
        case '\n':
            break;
        
        default:
            printf("ошибка: неизвестная операция %s\n", s);
            break;
            return 0;
        }
    }
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

int getop(char s[]) {
    int i, c;
    c = ' ';
    while(c == ' ' || c == '\t') {
        c = getch();
    }
    s[0]=c;
    
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
    if(c == 'p' || c == 's') { /* Всю эту конструкцию нужно повторно осознать */
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

    if(!isdigit(c) && c != '.' && c != '-')
        return c;

    i = 0;
    if(c == '-') {
        while(isdigit(s[++i] = c = getch()));
        if(i == 1) { /* зачем здесь эта проверка? */
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