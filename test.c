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
    printf("Enqueued %d\n",)
}
