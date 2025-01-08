//CLL
// Insert Front
// Display
// Insert rear
// delete rear
// search
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * link;
};
typedef struct node node;

node * getnode(int info){
    node *ptr = (node *)malloc(sizeof(node));
    ptr -> data= info;
    ptr -> link = NULL;
    return ptr;
}

node *cInsertFront(node * last , int ele){
    node * newnode = getnode(ele);
    if (last == NULL){
        last = newnode ;
        last ->link = last;
        return last;
    }
    newnode ->link = last ->link;
    last -> link = newnode;
    return last;
}
node * cInsertRear(node * last , int ele){
    node * newnode = getnode(ele);
    if(last == NULL){
        last = newnode;
        last -> link = newnode;
        return last;
    }
    newnode -> link = last -> link;
    last -> link = newnode;
    last = newnode;
    return last;
}
void Disp(node *last){
    if(last == NULL){
        return;
    }
    node * temp = last -> link;
    do{
        printf("%d\t ",temp -> data);
        temp = temp-> link;
    }while(temp != last ->link);
    printf("\n");
}
node *cDeleteRear(node * last){
    if (last == NULL){
        return last;
    }
    if(last -> link == last){
        free(last);
        return NULL;
    }
    node * temp = last -> link;
    while(temp -> link != last){
        temp = temp ->link;
    }
    temp -> link = last ->link;
    free(last);
    last = temp;
    return last;
}
int search(node * last , int ele){
    if(last == NULL){
        puts("Empty List");
    }
    node * temp = last -> link;
    int pos =1;
    do{
        if(temp -> data == ele){
            return pos;
        }
        temp = temp -> link;
        pos++;
    }while(temp != last -> link);
    return -1;
}
int main(){
    node *last = NULL;
    int choice , ele , result;
    while(1){
        printf("1. Insert at Front\n");
        puts("2. Display");
        puts("3. Insert Rear");
        puts("4. Delete Rear");
        puts("5. Search");
        puts("6. Exit");
        printf("Choice :");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at front");
                scanf("%d",&ele);
                last = cInsertFront(last,ele);
                break;
            case 2:
                Disp(last);
                break;
            case 3:
                printf("Enter the element to insert at front");
                scanf("%d",&ele);
                last = cInsertRear(last,ele);
                break;
            case 4:
                last = cDeleteRear(last);
                break;
            case 5:
                printf("Enter the element to search:");
                scanf("%d",&ele);
                result = search(last ,ele);
                if(result == -1) {
                    printf("Ele not found\n");
                }
                else{
                    printf("Ele found at : %d",result);
                }
                break;
            case 6:
                puts("bye...");
                exit(1);
            default:
                puts("Invalid choice....");

        }
    }
    return 0;
}
//CLL
// Insert Front
// Display
// Insert rear
// delete rear
// search
