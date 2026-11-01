//Write a C program to Sort given elements using Selection sort largest element method.
#include <stdio.h>
int main() {
    int arr[50], n, i, j, max, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n-1; i++) {
        max = 0;
        for(j = 1; j < n-i; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        temp = arr[n-i-1];        
        arr[n-i-1] = arr[max];     
        arr[max] = temp;
    }
    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}