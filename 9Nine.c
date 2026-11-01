//Operation on Stack using arrays.
#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed to stack.\n", value);
}
int pop() {
    if (top < 0) {
        printf("Stack Underflow.\n");
        return -1;
    }
    return stack[top--];
}   
int peek() {
    if (top < 0) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack[top];
}
int main() {
    printf("Stack Operations:\n");
    int choice, value;
    while (1) {
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("%d popped from stack.\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element is %d.\n", value);
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}