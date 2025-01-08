#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
typedef struct node node;

struct Queue{
    node * front , * rear;
};
typedef struct Queue Queue;

node * getnode (int data){
    node * ptr= (node *)malloc(sizeof(node));
    if(ptr != NULL){
        ptr -> data = data;
        ptr -> link = NULL;
    }
    return ptr;
}
int isEmpty(Queue *q){
    return (q->front == NULL);
}
void enqueue(Queue *q , int ele){
    node * newnode = getnode(ele);
    if(isEmpty(q)){
        q->front = q->rear = newnode;
    }else{
        q->rear -> link = newnode;
        q->rear = newnode;
    }
    printf("Enqueued %d\n",ele);
}
int dequeue(Queue *q){
    if(isEmpty(q)){
        puts("Queue underflown");
        return 0;
    }
    node * temp = q->front;
    int dequeu = temp ->data;
    q->front = q->front->link;

    if(q->front == NULL){
        q->rear = NULL;
    }
    free(temp);
    printf("Dequeued : %d",dequeu);
    return -1;
}
void disp(Queue *q){
    if(isEmpty(q)){
        puts("Queue is empty");
        return;
    }
    node * temp = q->front;
    printf("Queue element are: ");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp = temp -> link;
    }
    puts("");
}
int main(){
    Queue q;
    q.front = q.rear = NULL;
    int choice,data;

    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the element:");
                scanf("%d",&data);
                enqueue(&q, data);
                break;
            case 2:
                data =dequeue(&q);
                break;
            case 3:
                disp(&q);
                break;
            case 4:
                puts("Terminatnig....");
                exit(1);
            default:
                printf("Invalid");
        }
    }
    return 0;
}
