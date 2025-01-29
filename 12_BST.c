#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *left, *right;
};

typedef struct node node;

node * getnode(int info) {
    node * ptr;
    ptr = (node *)malloc(sizeof(node));
    if(ptr != NULL) {
        ptr->data = info;
        ptr->left = ptr->right = NULL;
    }
    return ptr;
}

node * insert(node * root, int ele) {
    node * newnode = getnode(ele);
    if(root == NULL)
        return newnode;

    if(root->data > ele) {
        root->left = insert(root->left, ele);
    } else {
        root->right = insert(root->right, ele);
    }

    return root;
}

void displayAscending(node * root) {
    if (root == NULL)
        return;

    displayAscending(root->left);
    printf("%d ", root->data);
    displayAscending(root->right);
}

int findLowestScore(node * root) {
    if(root == NULL)
        return -1;

    while(root->left != NULL)
        root = root->left;
    return root->data;
}

int findHighestScore(node * root) {
    if(root == NULL)
        return -1;

    while(root->right != NULL)
        root = root->right;
    return root->data;
}

int searchScore(node * root, int score) {
    if(root == NULL)
        return 0;

    if(root->data == score)
        return 1;

    if(root->data > score)
        return searchScore(root->left, score);
    else
        return searchScore(root->right, score);
}

int main() {
    node * root = NULL;
    int choice, score;

    while(1) {
        printf("\nStudent Score Management System\n");
        printf("1. Insert student score\n");
        printf("2. Display scores in ascending order\n");
        printf("3. Display highest and lowest scores\n");
        printf("4. Search for a score\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter student score (1-100): ");
                scanf("%d", &score);
                root = insert(root, score);
                break;

            case 2:
                printf("Scores in ascending order: ");
                displayAscending(root);
                printf("\n");
                break;

            case 3:
                if(root == NULL) {
                    printf("No scores available!\n");
                } else {
                    int lowest = findLowestScore(root);
                    int highest = findHighestScore(root);
                    printf("Lowest score: %d\n", lowest);
                    printf("Highest score: %d\n", highest);
                }
                break;

            case 4:
                printf("Enter score to search: ");
                scanf("%d", &score);
                if(searchScore(root, score))
                    printf("Score %d exists in the system.\n", score);
                else
                    printf("Score %d does not exist in the system.\n", score);
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
