//Write a C program to search an element using linear search process.
#include <stdio.h>
int main() {
    int n, i,arr[20], key, found = 0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at position %d (index %d).", i + 1, i);
            found = 1;
            break; 
        }
    }
    if (found == 0) {
        printf("Element not found in the array.");
    }
    return 0;
}