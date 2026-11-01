//To implement Binary Tree using Arrays. make it user defined
#include <stdio.h>
#define MAX 50
char tree[MAX];
void init() {
    for (int i = 0; i < MAX; i++) {
        tree[i] = '\0';
    }
}
void setRoot(char val) {
    tree[0] = val;
}
void setLeft(char val, int parent) {
    if (tree[parent] == '\0') {
        printf("Cannot set child, parent does not exist\n");
    } else {
        tree[(2 * parent) + 1] = val;
    }
}
void setRight(char val, int parent) {
    if (tree[parent] == '\0') {
        printf("Cannot set child, parent does not exist\n");
    } else {
        tree[(2 * parent) + 2] = val;
    }
}
void display() {
    printf("Binary Tree array representation:\n");
    for (int i = 0; i < 15; i++) {
        if (tree[i] != '\0') {
            printf("%c ", tree[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}
int main() {
    init();
    setRoot('A');
    setLeft('B', 0);
    setRight('C', 0);
    setLeft('D', 1);
    setRight('E', 1);
    setLeft('F', 2);
    setRight('G', 2);
    display();
    return 0;
}