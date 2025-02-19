#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int data;
    int count; // To track the number of occurrences
    struct node *left, *right;
};

// Function to create a new node
struct node* getnode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->count = 1;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Function to insert an element into the BST
struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return getnode(value);
    }
    if (value == root->data) {
        root->count++; // Increment count if duplicate is found
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to traverse the BST and print duplicates
void inorder_traversal(struct node* root) {
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    if (root->count > 1) {
        printf("%d appears %d times\n", root->data, root->count);
    }
    inorder_traversal(root->right);
}

int main() {
    struct node* root = NULL;
    int n, i, value;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Insert elements into the BST
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Display duplicates
    printf("\nDuplicate elements:\n");
    inorder_traversal(root);

    return 0;
}
