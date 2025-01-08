#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};
typedef struct node node;

node * getnode(int info){
    node * ptr = (struct node*)malloc(sizeof(node));
    if(ptr!=NULL){
        ptr -> data = info;
        ptr -> link = NULL;
    }
    return ptr;
}

node * insert_front (node *root , int data){
    node * newnode = getnode(data);
    if(newnode == NULL){
        puts("Memory Alloc failed\n");
        return root;
    }
    if(root == NULL){
        return newnode;
    }
    newnode -> link = root;
    return newnode;
}

node * delete_rear (node * root){
    if (root == NULL){
        puts("List is empty\n");
        return root;
    }
    if(root -> link == NULL){
        printf("Deleted ele : %d\n", root ->data);
        free(root);
        return NULL;
    }
    node * temp = root, *prev = NULL;
    while (temp -> link != NULL){
        prev = temp;
        temp = temp->link;
    }

    printf("deleted ele : %d",temp ->data);
    prev ->link = NULL;
    free(temp);
    return root;
}

int searchLL(node * root , int ele){
    if(root == NULL){
        puts("List empty");
        return -2;
    }
    node * temp= root;
    int pos = 0;
    while (temp != NULL){
        pos++;
        if(temp -> data == ele){
            return pos;
        }
        temp = temp ->link;
    }
    return -1;
}

void Disp(node *root){
    if(root == NULL){
        puts("Empty List");
        return;
    }
    if(root-> link == NULL){
        printf("Single ele: %d",root -> data);
        return;
    }
    node * temp = root;
    printf("List elements are: ");
    while(temp != NULL){
        printf(" %d\t",temp->data);
        temp = temp->link;
    }
    puts("");
}
// SLL
// Insert at front
// Delete at rear
// search for ele
// Disp
int main(){
    node * root = NULL;
    int choice , data , pos;

    while(1){
        puts("1. Insert Front");
        puts("2. Delete Rear");
        puts("3. Search LL");
        puts("4. Display");
        puts("5. Exit");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d",&data);
                root = insert_front(root,data);
                break;
            case 2:
                root = delete_rear(root);
                break;
            case 3:
                printf("Enter element to be searched");
                scanf("%d",&data);
                pos = searchLL(root , data);
                if (pos == -1){
                    puts("Element not found");
                }
                else{
                    printf("The element found at: %d",pos);
                }
                break;
            case 4:
                Disp(root);
                break;
            case 5:
                puts("Byee....");
                break;
            default :
                puts("invalid choice....");
        }
    }
    return 0;
}
