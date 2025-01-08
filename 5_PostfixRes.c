#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define max 50

struct stack{
    double st[max];
    int Top;
};
typedef struct stack stk;

void push(stk *s, double val){
    if(s->Top == max -1){
        puts("Stack Overflow");
        exit(1);
    }
    s->st[++s->Top] = val;
}

double pop(stk *s){
    if(s->Top == -1){
        puts("Stk Underflown");
        exit(1);
    }
    double val = s->st[s->Top--];
    return val;
}

double operation (double op1 , char symb, double op2){
    switch(symb){
        case '+':   return (op1+op2);
        case '-':   return (op1-op2);
        case '*':   return (op1*op2);
        case '/':   if(op2 == 0){
                        puts("not divisible");
                        exit(1);
                    }
                    return (op1/op2);
        case '$':   return (pow(op1,op2));
        default :
                    puts("Invalid Op used;");
                    exit(1);
    }
}

double post_eval(char postfix[]){
    double res , op1 ,op2;
    char symb;
    stk S1;
    S1.Top = -1;

    for (int i = 0 ; i < strlen(postfix);i++){
        symb=postfix[i];
        if (isdigit(symb)){
            push(&S1,symb - '0');
        }
        else {
            op2 = pop(&S1);
            op1 = pop(&S1);
            res = operation (op1,symb,op2);
            push(&S1,res);
        }
    }
    return pop(&S1);
}

int main(){
    char postfix[20];

    printf("Enter the post fix expressions:");
    scanf("%s",postfix);

    printf("Resutl of the given expression is : %lf\n",post_eval(postfix));
    return 0;
}
