//C program to Sort given elements using quick Sort.
#include <stdio.h>
int QuickSort(int arr[], int lb, int ub);
int Partition(int arr[], int lb, int ub);
int QuickSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int loc = Partition(arr, lb, ub);
        QuickSort(arr, lb, loc - 1);
        QuickSort(arr, loc + 1, ub);
    }
    return 0;
}
int Partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while (start < end) {
        while (arr[start] <= pivot && start < ub) {
            start++;
        }
        while (arr[end] > pivot) {
            end--;
        }
        if (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;
    return end;
}
int main() {
    int arr[50], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    QuickSort(arr, 0, n - 1);
    printf("Sorted elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}