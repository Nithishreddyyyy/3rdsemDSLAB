#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * link;
};
typedef struct node node;

node * front = NULL;
node * rear = NULL;

node * getnode(int info){
    node * ptr = (node *)malloc(sizeof(node));
    if(ptr!=NULL){
        ptr->data = info;
        ptr->link = NULL;
    }
    return ptr;
}

node * enqueue(node * front , int data){
    node * newnode = getnode(data);
    if(newnode == NULL){
        puts("memory alloc failed!");
        return front;
    }
    if(rear == NULL){
        front = rear = newnode;
    }
    else{
        rear ->link = newnode;
        rear = newnode;
    }
    return front;
}

node * dequeue (node * front){
    if(front == NULL){
        printf("Queue is empty");
        return front;
    }
    node * temp = front;
    printf("Dequeued :%d" , temp -> data);
    front = front -> link;
    if(front == NULL){
        rear = NULL;
    }
    free(temp);
    return front;
}

void Disp(node * front){
    if(front ==NULL){
        printf("queue is empty");
        return;
    }
    printf("Queue elements are: ");
    node * temp = front ;
    while(temp != NULL){
        printf("%d   ",temp->data);
        temp = temp->link;
    }
    puts("");
}

int main(){
    int choice , value;
    while(1){
        puts("1. Enqueue");
        puts("2. Dequeue");
        puts("3. Display");
        puts("4. Exit");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the ele: ");
                scanf("%d",&value);
                front = enqueue (front , value);
                break;
            case 2:
                front = dequeue(front);
                puts("");
                break;
            case 3:
                Disp(front);
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid option");
        }
    }
}
