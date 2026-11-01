//Binary Tree Traversal using Linked List -Non-Recursive.
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* stack[MAX];
int top = -1;
void push(struct Node* node) {
    if (top < MAX - 1) {
        stack[++top] = node;
    }
}
struct Node* pop() {
    if (top != -1) {
        return stack[top--];
    }
    return NULL;
}
int isEmpty() {
    return top == -1;
}
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
void inorderNonRecursive(struct Node* root) {
    struct Node* curr = root;
    while (curr != NULL || !isEmpty()) {
        while (curr != NULL) {
            push(curr);
            curr = curr->left;
        }
        curr = pop();
        printf("%d ", curr->data);
        curr = curr->right;
    }
}
void preorderNonRecursive(struct Node* root) {
    if (root == NULL) return;
    push(root);
    while (!isEmpty()) {
        struct Node* curr = pop();
        printf("%d ", curr->data);
        if (curr->right != NULL) {
            push(curr->right);
        }
        if (curr->left != NULL) {
            push(curr->left);
        }
    }
}
int main() {
    struct Node* root = NULL;
    printf("Create Binary Tree:\n");
    root = createTree();
    printf("\nNon-Recursive Inorder Traversal: ");
    inorderNonRecursive(root);
    printf("\nNon-Recursive Preorder Traversal: ");
    preorderNonRecursive(root);
    printf("\n");
    return 0;
}