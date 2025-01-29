#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct Stack{
    int st[MAX];
    int Top;
};
typedef struct Stack S1;

int isEmpty(S1 s){
    return (s.Top == -1);
}

int isFULL(S1 s){
    return (s.Top == MAX - 1);
}

void push(S1 *s, int item){
    if(isFULL(*s)){
        puts("\nStack UnderFlown");
    }
    else{
        s->st[++s->Top] = item;
        printf("Element has been pushed into the stack");
    }
}

int pop(S1 *s){
    if(isEmpty(*s)){
        puts("Stack Underflown");
        return -1;
    }
    else {
        int item = s->st[s->Top--];
        return item;
    }
}

void disp(S1 *s){
    if(isEmpty(*s)){
        puts("Stack is empty");
    }
    else{
        for(int i = s->Top ; i>=0 ; i--){
            printf("%d  ",s->st[i]);
        }
    }
}

int isPali(S1 *s){
    if(isEmpty(*s)){
        puts("Stack is empty");
        return 0;
    }
    int temp[MAX];
    int count = 0;

    for (int i = 0 ; i <= s->Top ; i++){
        temp[i] = s->st[i];
        count ++;
    }

    for (int i = 0; i < count / 2; i++) {
        if(temp[i] != temp[count - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main(){
    S1 sta;
    int choice,ele;
    sta.Top = -1;
    while(1){
        printf("\nThe Following Operations:\n");
        printf("1. Push an element of your choice.\n2. Pop the topmost element of the stack.\n3. Display all elements of the stack.\n4. Palindrome check using staks.\n5. Exit");
        printf("\nChoose the operation: ");
        scanf("%d",&choice);
        printf("\n");

        switch(choice){
            case 1: //Push
                printf("Enter the element that has to be pushed into the stack: ");
                scanf("%d",&ele);
                push(&sta,ele);
                break;
            case 2: //pop
                ele = pop(&sta);
                if (ele != -1)
                    printf("The poped element is : %d",ele);
                else
                    puts("pop Unsuccessful");
                break;
            case 3: //Disp
                printf("The elements in the stack are as follows\n");
                printf("[");
                disp(&sta);
                printf("]");
                break;
            case 4:
                if(isPali(&sta)){
                    puts("The stack is PALINDROME");
                }
                else{
                    puts("The stack is not PALINDROME");
                }
                break;
            case 5:
                printf("The code has been terminated");
                exit(1);
        }
        printf("\n");
    }
}
