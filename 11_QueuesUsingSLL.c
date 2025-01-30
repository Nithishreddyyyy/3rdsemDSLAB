#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node node;
node *getnode(int info)
{
    node *ptr;
    ptr = (node *)malloc(1*sizeof(node));
    ptr->data=info;
    ptr->link=NULL;
    return ptr;
}
node *insert_rear(node *root, int info) {
    node *newnode = getnode(info);
    if (root == NULL) {
        return newnode;
    }
    node *temp = root;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newnode;
    return root;
}
node *delete_front(node *root) {
    if (root == NULL) {
        printf("Queue is empty! Cannot dequeue.\n");
        return NULL;
    }
    node *temp = root;
    printf("The dequeued data is %d\n", temp->data);
    root = root->link;
    free(temp);
    return root;
}
void display(node *root)
{
    node *temp;
    temp=root;
    if(root==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
int main()
{
    int choice,ele;
    struct node *root;
    root = NULL;
    printf("Choose an option:\t1.insert rear\t2.delete front\t3.Display\t4.exit\n");
    while(1)
    {
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("enter data:");
                scanf("%d",&ele);
                root=insert_rear(root,ele);
                break;
            case 2:
                root=delete_front(root);
                break;
            case 3:
                display(root);
                break;
            case 4:
                printf("Exiting....\n");
                return 0;
            default:
                printf("Enter a valid choice\n");
        }
    }
    return 0;
}
