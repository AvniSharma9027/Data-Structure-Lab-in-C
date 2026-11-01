//Operation on Queue using arrays.  
#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int value) {
    if (rear >= MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = value;
    printf("%d enqueued to queue.\n", value);
}
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow.\n");
        return -1;
    }
    int value = queue[front++];
    return value;
}
int peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[front];
}
int main() {
    printf("Queue Operations:\n");
    int choice, value;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("%d dequeued from queue.\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Front element is %d.\n", value);
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}