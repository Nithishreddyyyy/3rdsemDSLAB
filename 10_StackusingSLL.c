#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * link;
};
typedef struct node node;

node * getnode(int info){
    node * ptr = (node *)malloc(sizeof(node));
    if(ptr != NULL){
        ptr -> data = info;
        ptr -> link = NULL;
    }
    return ptr;
}

node * Push(node * top , int item){
    node * newnode = getnode(item);
    if(newnode == NULL){
        puts("memory alloc failed");
        return top;
    }
    newnode -> link = top;
    printf("Pushed ele :%d\n",item);
    return newnode;
}
node * Pop(node * top){
    if (top == NULL){
        puts("Stk Underflown");
        return top;
    }
    node * temp = top;
    int pop = top -> data;
    top = top->link;
    free(temp);
    printf("Poped ele: %d\n",pop);
    return top;
}
void Disp(node * top){
    if(top == NULL){
        printf("Stk Underflown");
        return;
    }
    node * temp = top;
    printf("Stk elements: ");
    while(temp != NULL){
        printf("\t%d\t",temp -> data);
        temp= temp->link;
    }
    puts("");
}
int main(){
    node * top = NULL;
    int choice , ele;
    while(1){
        puts("1. Push");
        puts("2. Pop");
        puts("3. Display");
        puts("4. Exit");
        printf("Enter choice ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("enter ele: ");
                scanf("%d",&ele);
                top = Push (top , ele);
                break;
            case 2:
                top = Pop(top);
                break;
            case 3:
                Disp(top);
                break;
            case 4:
                puts("Terminated .....");
                exit(1);
            default :
                printf("Invalid");
        }
    }
    return 0;
}
