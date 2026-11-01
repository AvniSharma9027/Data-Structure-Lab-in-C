//Write a C Program to sort given elements using Merge sort.
#include <stdio.h>  
int Merge(int arr[], int lb, int mid, int ub);
int MergeSort(int arr[], int lb, int ub);
int MergeSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb+ub)/ 2;
        MergeSort(arr, lb, mid);
        MergeSort(arr, mid + 1, ub);
        Merge(arr, lb, mid, ub);
    }
    return 0;
}
int Merge(int arr[], int lb, int mid, int ub) {
    int arr1[50];
    int i, j, k;
    i = k = lb;
    j = mid + 1;
    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j]) {
            arr1[k++] = arr[i++];
        } 
        else {
            arr1[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        arr1[k++] = arr[i++];
    }
    while (j <= ub) {
        arr1[k++] = arr[j++];
    }
    for (i = lb; i <= ub; i++) {
        arr[i] = arr1[i];
    }
    return 0;
}
int main() {
    int arr[50], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    MergeSort(arr, 0, n - 1);
    printf("Sorted elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}