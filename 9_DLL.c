#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev , *next;
};
typedef struct node node;

node * getnode (int info){
    node * ptr = (node *)malloc(sizeof(node));
    if(ptr != NULL){
        ptr -> data = info;
        ptr -> prev = ptr ->next = NULL;
    }
    return ptr;
}
node *insert_front (node * root , int data){
    node * newnode = getnode(data);
    if(newnode==NULL){
        puts("Memeory Alloc Faield!\n");
        return root;
    }
    if(root == NULL){
        return newnode;
    }
    root -> prev = newnode;
    newnode -> next = root ;
    return newnode;
}
node * insert_rear (node * root , int data){
    node * newnode = getnode (data);
    if(newnode == NULL){
        puts("Memeory Alloc failed");
    }
    if(root == NULL){
        return newnode;
    }
    node * temp = root;
    while (temp -> next != NULL){
        temp = temp ->next;
    }
    temp ->next = newnode;
    newnode -> prev = temp;
    return root;
}
node * delete_front(node * root){
    if (root == NULL){
        puts("no elements in the list");
        return root;
    }
    node * temp = root ;
    root = root -> next;
    printf("Deleted elelment is : %d\n",temp -> data);
    free(temp);
    return root;
}
void Disp(node *root){
    if(root == NULL){
        puts("No elements in list\n");
        return;
    }
    printf("Fwd traversal");
    node *temp = root;
    while(temp!=NULL){
        printf("\t%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int SearchLL(node *root , int key){
    if(root == NULL){
        printf("No elements in list");
    }
    node * temp = root;
    int pos =0;
    while (temp != NULL){
        pos ++;
        if(temp -> data == key){
            return pos;
        }
        temp = temp->next;
    }
    return -1;
}

int main(){
    node * root = NULL;
    int choice , data , pos;

    while (1){
        printf("\nOperations\n");
        puts("1. Insert Rear");
        puts("2. Display");
        puts("3. Insert Front");
        puts("4. Delete Front");
        puts("5. Search");
        puts("6. Exit");
        printf("Chooice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d",&data);
                root = insert_rear(root, data);
                break;
            case 2:
                Disp(root);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d",&data);
                root = insert_front(root,  data);
                break;
            case 4:
                root = delete_front(root);
                break;
            case 5:
                printf("Enter key: ");
                scanf("%d",&data);
                pos= SearchLL(root, data);
                if(pos != -1){
                    printf("The position is: %d\n",pos);
                }else{
                    puts("Not found\n");
                }
                break;
            case 6:
                puts("termination....");
                exit(1);
            default :
                printf("Invalid options");
        }
    }
    return 0;
}
