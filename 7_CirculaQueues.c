#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct CQueue {
    char items[MAX];
    int front, rear;
};
typedef struct CQueue CQ;

int isEmpty(CQ c) {
    return (c.rear == -1 && c.front == -1);
}

int isFull(CQ c) {
    return ((c.rear + 1) % MAX == c.front);
}

void Cenqueue(CQ *c1, char ele) {
    if(isFull(*c1)) {
        puts("\nCircular Queue is FULL");
        return;
    }
    if(isEmpty(*c1))
        c1->front = 0;
    c1->rear = (c1->rear + 1) % MAX;
    c1->items[c1->rear] = ele;
    printf("\nCharacter '%c' enqueued into queue", ele);
}

char Cdequeue(CQ *c) {
    char item;
    if(isEmpty(*c)) {
        puts("\nCircular Queue is EMPTY");
        return '\0';
    }
    item = c->items[c->front];
    if(c->front == c->rear) {
        c->front = c->rear = -1;   //Empty Queue
    } else {
        c->front = (c->front + 1) % MAX;
    }
    return item;
}

void display(CQ c) {
    if(isEmpty(c)) {
        puts("\nCircular Queue is EMPTY");
        return;
    }

    int i = c.front;
    printf("\nQueue elements are: ");
    while(i != (c.rear + 1) % MAX) {
        printf("%c ", c.items[i]);
        i = (i + 1) % MAX;
    }
    puts("");
}


int main() {
    CQ Q1;
    Q1.front = Q1.rear = -1;
    int choice;
    char ele;

    while(1) {
        printf("\nCircular Queue Operations\n");
        puts("1. Insert an Element");
        puts("2. Delete an Element");
        puts("3. Display Queue");
        puts("4. Exit");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch(choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &ele);
                Cenqueue(&Q1, ele);
                break;
            case 2:
                ele = Cdequeue(&Q1);
                if(ele != '\0')
                    printf("\nDeleted character: %c\n", ele);
                break;
            case 3:
                display(Q1);
                break;
            case 4:
                puts("\nExiting Program...");
                exit(0);
            default:
                puts("\nInvalid Choice!");
        }
    }
    return 0;
}
