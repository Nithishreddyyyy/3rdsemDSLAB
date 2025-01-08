#include <stdlib.h>
#include <stdio.h>
struct node{
    int data;
    struct node *link;
};
typedef struct node node;
struct Queue{
    node * front , *rear;
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
void enqueue (Queue *q , int data){
    node * newnode = getnode(data);
    if (isEmpty(q)){
        q->front = q->rear = newnode;
    }else{
        q->rear -> link = newnode;
        q->rear = newnode;
    }
    printf("Enqueued %d\n",data);
}
int dequeue(Queue *q ){
    if(isEmpty(q)){
        puts("Queue Underflown");
        return 0;
    }
    node * temp = q->front;
    int dequeued = temp ->data;
    q->front = q->front->link;
    if(q->front == NULL){
        q->rear = NULL;
    }
    free(temp);
    printf("Dequeued ele: %d\n",dequeued);
    return 1;
}
void display(Queue *q){
    if(isEmpty(q)){
        puts("Queue is empty.\n");
        return;
    }
    node * temp = q->front;
    printf("Queue elements are: ");
    while(temp != NULL){
        printf("%d\t",temp -> data);
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
                display(&q);
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
