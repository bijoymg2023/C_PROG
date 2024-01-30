#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary tree
struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
};

struct node *root = NULL;

// Function to create a new node
struct node *new(int val) {
    struct node *head = malloc(sizeof(struct node));
    head->data = val;
    head->lchild = NULL;
    head->rchild = NULL;
    return head;
}

// Function to insert a value into the binary tree
struct node *insert(struct node *root, int val) {
    if (root == NULL) {
        return new(val);
    }
    if (val < root->data) {
        root->lchild = insert(root->lchild, val);
    } else if (val > root->data) {
        root->rchild = insert(root->rchild, val);
    }
    return root;
}

// Function to perform in-order traversal
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
        
    }
}

// Function to perform pre-order traversal
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

// Function to perform post-order traversal
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}

// Function to mirror the binary tree
void mirror(struct node *root) {
    if (root != NULL) {
        mirror(root->lchild);
        mirror(root->rchild);
        struct node *temp = root->lchild;
        root->lchild = root->rchild;
        root->rchild = temp;
    }
}
//Not working.........................................
void leafnode(struct node* root)
{
if (root==NULL)
{
    return;
}
  
    if(root->lchild==NULL && root->rchild==NULL)
    {
        printf("\nLEAF NODES:%d\t",root->data);
    }
      leafnode(root->lchild);
    leafnode(root->rchild);
}
// Function to traverse the binary tree
void traverse() {
    int n = 0;
    while (n != 4) {
        printf("\n1.INORDER\t2.PREORDER\t3.POSTORDER\t4.EXIT\n");
        printf("ENTER CHOICE:\t");
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("INORDER:\t");
                inorder(root);
                break;
            case 2:
                printf("PREORDER:\t");
                preorder(root);
                break;
            case 3:
                printf("POSTORDER:\t");
                postorder(root);
                break;
        }
    }
}

// Main function
void main() {
    int value, n = 0;
    while (n != 6) {
        printf("\n1.INSERT\t2.TRAVERSE\t3.MIRROR \t4.LEAF NODE\t5.EXIT\n");
        printf("ENTER CHOICE:\t");
        scanf("%d", &n);
        switch (n) {
            case 1: {
                int m = 1;
                while (m != 0) {
                    printf("ENTER VALUE:");
                    scanf("%d", &value);
                    root = insert(root, value);
                    printf("PROCEED?(1/0):");
                    scanf("%d", &m);
                }
                break;
            }
            case 2: {
                if (root == NULL) {
                    printf("EMPTY TREE");
                    break;
                }
                traverse();
                break;
            }
            case 3:
                mirror(root);
                break;
            case 4:
                leafnode(root);
            case 5:
                exit(0);
        }
    }
}
