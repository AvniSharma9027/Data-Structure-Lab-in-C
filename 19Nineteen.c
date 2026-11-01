//To Implement Binary Search Tree Using Arrays.
#include <stdio.h>
#define MAX 50
int tree[MAX];
void init() {
    for (int i = 0; i < MAX; i++) {
        tree[i] = -1;
    }
}
void insert(int val) {
    if (tree[0] == -1) {
        tree[0] = val;
        return;
    }
    int i = 0;
    while (i < MAX) {
        if (tree[i] == -1) {
            tree[i] = val;
            break;
        }
        if (val < tree[i]) {
            i = 2 * i + 1; // Left child
        } else {
            i = 2 * i + 2; // Right child
        }
    }
}
void display() {
    printf("BST Array Representation:\n");
    for (int i = 0; i < 15; i++) {
        if (tree[i] != -1) {
            printf("%d ", tree[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}
int main() {
    init();
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);
    display();
    return 0;
}