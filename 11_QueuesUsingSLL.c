#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
typedef struct node node;

node * getnode (int info){
    node * ptr = (node *)malloc(sizeof(node));
    if(ptr!=NULL){
        ptr->data = info;
        ptr->link=NULL;
    }
    return ptr;
}

node * enqueue(node * root , int data){ //Insert REAR
    node * newnode = getnode(data);
    if (newnode == NULL){
        puts("Memory Alloc failed!");
        return newnode;
    }
    if(root == NULL){
        return newnode;
    }
    node * temp = root;
    while(temp -> link !=NULL){
        temp = temp->link;
    }
    temp -> link = newnode;
    return root;
}

node * dequeue(node * root){    //delete front
    if(root == NULL){
        puts("No elements in the list");
        return root;
    }
    node * temp = root;
    printf("The dequeued ele is: %d",temp->data);
    root = root -> link;
    free(temp);
    return root;
}

void disp(node * root){
    if(root == NULL){
        puts("Empty List");
        return;
    }
    node * temp = root;
    while(temp!=NULL){
        printf("\t%d\t",temp->data);
        temp = temp -> link;
    }
    puts("");
}

int main(){
    struct node * root = NULL;
    int choice,ele;
    while(1){
        puts("1.Enqueue");
        puts("2.Dequeue");
        puts("3.Disp");
        puts("4.Exit");
        printf("Enter your choice:  ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter ele to enqueue");
                scanf("%d",&ele);
                root = enqueue(root,ele);
                break;
            case 2:
                root = dequeue(root);
                break;
            case 3:
                disp(root);
                break;
            case 4:
                puts("Terminatingggg");
                exit(1);
                break;
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}
