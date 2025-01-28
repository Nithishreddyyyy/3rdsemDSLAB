#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max 5
struct stack{
    char sy[max];
    int top;
};
typedef struct stack S1;

int inp_prec(char symbol){
    switch (symbol){
        case '+':
        case '-':   return 1;
        case '*':
        case '/':   return 3;
        case '$':
        case '^':   return 6;
        case ')':   return 9;
        case '(':   return 0;
        default :   return 7;
    }
}
int stack_prec(char symbol){
    switch (symbol) {
        case '+':
        case '-':   return 2;
        case '*':
        case '/':   return 4;
        case '$':
        case '^':   return 5;
        case '(':   return 0;
        case '#':   return -1;
        default :   return -2;
    }
}

int isFull(S1 s){
    return(s.top == max - 1);
}

int isEmpty(S1 s){
    return (s.top == -1);
}

void push(S1 *s, char item){
    if(isFull(*s)){
        puts("\nStack Overflow");
    }
    else {
        s->sy[++s->top] = item;
    }
}

char pop(S1 *s){
    if(s->top == -1){
        puts("\nStack Underflow");
        return '\0';
    }else{
        return s->sy[s->top--];
    }
}

void inf_post(char *infix , char * postfix){

}
