#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev,*next;
};
typedef struct node node ;
node * getnode()
