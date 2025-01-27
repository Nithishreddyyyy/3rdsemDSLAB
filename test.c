#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * link;
};
typedef struct node node;

node * getnode (int info){
    node * ptr = (node *)malloc(sizeof(node));
    if(ptr != NULL){
        ptr -> data = info;
        ptr -> link = NULL;
    }
    return ptr;
}

node * insert_front (node * root , int data){
    node * newnode = getnode(data);
    if(newnode == NULL){
        puts("Memory alloc failed\n");
        return root;
    }
    if(root == NULL){
        return newnode;
    }
    newnode -> link = root;
    return newnode;
}

node * delete_rear (node * root){
    if(root == NULL){
        puts("List is empty");
        return root;
    }
    if(root ->link == NULL){
        printf("Deleted ele: %d\n",root -> data);
        free(root);
        return NULL;
    }
    node * temp= root,* prev = NULL;
    while(temp -> link != NULL){
        prev = temp;
        temp = temp->link;
    }

    printf("deleted ele : %d",temp -> data);
    prev -> link = NULL;
    free(temp);
    return root;
}

int searchLL(node * root , int ele){
    if(root == NULL){
        puts("Empty");
        return -2;
    }
    node * temp = root;
    int pos = 0;
    while(temp != NULL ){
        pos++;
        if(temp -> data == ele){
            return pos;
        }
        temp = temp->link;
    }
    return -1;
}

void Disp(node * root){
    if(root == NULL){
        puts("Empty List");
        return;
    }
    if(root -> link == NULL){
        printf("Single ele : %d",root -> data);
        return;
    }
    node * temp = root;
    printf("List ele are : ");
    while(temp != NULL){
        printf("%d\t",temp -> data);
        temp = temp -> link;
    }
    puts("");
}

int main(){
    node * root = NULL;
    int choice , data
}
