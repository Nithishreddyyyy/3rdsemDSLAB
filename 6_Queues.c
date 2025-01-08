#include <stdio.h>
#include <stdlib.h>
#define Max 10

struct Queue{
    int pid[Max];
    int front,rear;
};
typedef struct Queue Q;

int isFull(Q q){
    return (q.rear == Max -1);
}

int isEmpty(Q q){
    return (q.front > q.rear);
}

void addProcess(Q *q, int item){
    if (isFull(*q)){
        puts("Process Queue is full!!");
    }
    q->pid[++q->rear] = item;
}

int removeProcess(Q *q){
    if(isEmpty(*q)){
        printf("Process Queue is empty!! No processes to remove");
        return -1;
    }
    int removed = q->pid[q->front++];
    return removed;
}

void Disp(Q q){
    if(isEmpty(q)){
        puts("No process in the queue\n");
        return;
    }
    printf("Processes in the queue are:");
    for (int i = q.front ; i<= q.rear ; i++){
        printf(" %d\t ",q.pid[i]);
    }
}

int main(){
    Q q;
    q.front = 0;
    q.rear = -1;
    int pid,choice;

    while(1){
        printf("\n1.Add Process\n2.Remove Process\n3.Display All process\n4. Exit\n");
        printf("Enter Choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter Pid: ");
                scanf("%d",&pid);
                addProcess(&q,pid);
                break;
            case 2:
                pid = removeProcess(&q);
                if(pid != -1){
                    printf("\nProcess ID %d removed from the queue\n",pid);
                }
                break;
            case 3:
                Disp(q);
                break;
            case 4:
                printf("\nTerminating Menu driven Program\nByee.....");
                exit(1);
            default:
                printf("Invalid choice choose again");
        }
    }
    return 0;
}
