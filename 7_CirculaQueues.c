#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct CQueue{
    int items[SIZE];
    int front , rear;
};
typedef struct CQueue C;

int isEmpty(C c){
    return(c.rear == -1 && c.front ==-1);
}

int isFull(C c){
    return ((c.rear + 1) % SIZE == c.front);
}
void Cenqueue(C *c1 , int ele){
    if(isFull(*c1)){
        puts("\nCircular queue is full");
        return;
    }
    if(isEmpty(*c1))
        c1->front = 0;
    c1->rear = (c1->rear + 1) % SIZE;
    c1->items[c1->rear] = ele;
    printf("%d enqueued into queue",ele);
}

int Cdequeue(C *c){
    int item;
    if(isEmpty(*c)){
        puts("Circular queue is empty");
        return -1;
    }
    item= c->items[c->front];
    if(c->front == c->rear){
        c->front = c-> rear = -1;   //Empty Queue
    }else{
        c->front = (c->front +1) %SIZE;
    }
    return item;
}

void disp(C c){
    if(isEmpty(c)){
        puts("Circular eueue is Empty");
        return ;
    }

    int i = c.front;
    printf("Queue elelemtns are :  ");
    while(i!=(c.rear+1)%SIZE){
        printf("%d\t",c.items[i]);
        i = (i+1)%SIZE;
    }
    puts("");
}
int main (){
    C C1;
    C1.front = C1.rear = -1;
    int choice , ele;
    while (1){
        printf("\nMenu\n");
        puts("1. Enqueue");
        puts("2. Dequeue");
        puts("3. Display");
        puts("4. Exit");
        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                printf("Enter the element: ");
                scanf("%d",&ele);
                Cenqueue(&C1, ele);
                break;
            case 2:
                ele = Cdequeue(&C1);
                if (ele != -1){
                    printf("The dequeued ele: %d",ele);
                }
                break;
            case 3:
                disp(C1);
                break;
            case 4:
                puts("Terminating the program");
                exit(1);
            default :
                printf("Invalid");
        }
    }
}
