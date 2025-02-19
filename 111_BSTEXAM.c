#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *right , *left;
};
typedef struct node node;

node * getnode(int info){
    node * ptr = (node *)malloc(sizeof(node));
    if(ptr !=NULL){
        ptr->data = info;
        ptr->right = ptr->left = NULL;
    }
    return ptr;
}

node * insert(node * root , int data){
    node * newnode = getnode(data);
    if (root == NULL)
        return newnode;

    if(root->data > data){
        root -> left = insert(root->left , data);
    }
    else{
        root->right = insert (root->right , data);
    }
    return root;
}

void inorder(node * root){
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}
void preorder(node * root){
    if(root == NULL)
        return;

    printf("%d->",root -> data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node * root){
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root -> right);
    printf("%d->",root->data);
}
int min(node * root){
    if(root == NULL){
        return -1;
    }
    while(root->left != NULL)
        root = root->left;
    return root->data;
}
int max(node * root){
    if(root == NULL){
        return -1;
    }
    while(root->right != NULL)
        root = root->right;
    return root->data;
}

int search(node * root , int score){
    if(root == NULL){
        return 0;
    }
    if(root -> data == score)
        return 1;
    if(root->data>score){
        return search(root->left , score);
    }
    else{
        return search(root->right, score);
    }
}

int count(node * root){
    if (root == NULL)
        return 0;
    if(root->right == NULL && root->left == NULL)
        return 1;

    return count(root->left)+ count (root -> right);
}

node* minNode(node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}
node* delete_BST(node* root, int ele) {
    if (root == NULL)
        return NULL;

    if (root->data > ele)
        root->left = delete_BST(root->left, ele);
    else if (root->data < ele)
        root->right = delete_BST(root->right, ele);
    else {
        // Case 1 & 2: Node has 0 or 1 child
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Node has 2 children (Use min function for inorder successor)
        node* temp = minNode(root->right);  // Get the inorder successor
        root->data = temp->data;        // Copy the inorder successor's data
        root->right = delete_BST(root->right, temp->data);  // Delete the successor
    }
    return root;
}

int main() {
    node* root = NULL;
    int choice, data, result;

    while(1) {
        printf("\n\nBinary Search Tree Operations:");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Inorder Traversal");
        printf("\n4. Preorder Traversal");
        printf("\n5. Postorder Traversal");
        printf("\n6. Find Minimum");
        printf("\n7. Find Maximum");
        printf("\n8. Search Element");
        printf("\n9. Count Leaf Nodes");
        printf("\n10. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Element inserted successfully!");
                break;

            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                root = delete_BST(root, data);
                printf("Element deleted successfully!");
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                break;

            case 6:
                result = min(root);
                if(result != -1)
                    printf("Minimum element: %d", result);
                else
                    printf("Tree is empty!");
                break;

            case 7:
                result = max(root);
                if(result != -1)
                    printf("Maximum element: %d", result);
                else
                    printf("Tree is empty!");
                break;

            case 8:
                printf("Enter element to search: ");
                scanf("%d", &data);
                if(search(root, data))
                    printf("Element found!");
                else
                    printf("Element not found!");
                break;

            case 9:
                printf("Number of leaf nodes: %d", count(root));
                break;

            case 10:
                printf("Exiting program...");
                exit(0);

            default:
                printf("Invalid choice! Please try again.");
        }
    }
    return 0;
}
