//Write a C program to search an element using Binary search process.
#include <stdio.h>
int main() {
    int n, i, arr[20], key, found = 0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements in sorted order: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    int first = 0, last = n - 1, mid;
    while (first <= last) {
        mid = (first + last) / 2;
        if (arr[mid] == key) {
            printf("Element found at position %d (index %d).", mid + 1, mid);
            found = 1;
            break;
        }
        else if (arr[mid] < key) {
            first = mid + 1;
        }
        else {
            last = mid - 1;
        }
    }
    if (found == 0) {
        printf("Element not found in the array.");
    }
    return 0;
}