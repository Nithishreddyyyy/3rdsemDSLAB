#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define Max 20

struct stack{
    char sy[Max];
    int top;
};
typedef struct stack S1;

int inp_prec(char symbol){
    switch(symbol){
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
    if(s.top == Max - 1)
        return 1;
    return 0;
}

int isEmpty(S1 s){
    if(s.top == -1)
        return 1;
    return 0;
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

void inf_post(char *infix , char *postfix){
    S1 S1;
    char symbol,ele;
    int i=0 , j=0;
    S1.top = -1;
    push(&S1,'#');
    for (i = 0 ; i < strlen(infix) ; i++){
        symbol = infix[i];
        if(isalnum(symbol)){
            postfix[j++] = symbol;
        }
        else{
            while(inp_prec(symbol) < stack_prec(S1.sy[S1.top])){
                ele = pop(&S1);
                postfix[j++] = ele;
            }
            if (inp_prec(symbol) != stack_prec(S1.sy[S1.top])){
                push(&S1 , symbol);
            }
            else{
                ele = pop(&S1);
            }
        }
    }
    while(S1.sy[S1.top] != '#'){
        postfix[j++] = pop(&S1);
    }
    postfix[j] = '\0';
}
int main(){
    char infix[20],postfix[20];
    printf("Enter the expression: ");
    scanf("%s",infix);
    inf_post(infix,postfix);
    puts("");
    printf("The postfix expressions is : %s",postfix);
    return 0;
}
