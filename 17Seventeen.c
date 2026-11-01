//Binary Tree Traversal Using Linked List -Recursive.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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
    struct Node* root = createNode(val);
    printf("Enter left child of %d:\n", val);
    root->left = createTree();
    printf("Enter right child of %d:\n", val);
    root->right = createTree();
    return root;
}
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    struct Node* root = NULL;
    printf("Create Binary Tree:\n");
    root = createTree();
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n");
    return 0;
}