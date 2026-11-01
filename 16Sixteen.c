//Implementation of Binary Tree Using Linked List.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* createTree() {
    int val;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &val);
    if (val == -1) {
        return NULL;
    }
    struct Node *root = createNode(val);
    printf("Enter left child of %d:\n", val);
    root->left = createTree();
    printf("Enter right child of %d:\n", val);
    root->right = createTree();
    return root;
}
void inorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main() {
    printf("Create Binary Tree:\n");
    struct Node *root = createTree();
    printf("\nInorder traversal of created tree: ");
    inorder(root);
    printf("\n");
    return 0;
}