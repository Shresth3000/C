#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // outer loop
        int mini = i; // assume min is i
        for (int j = i + 1; j < n; j++) { // start from next element
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        // swap arr[mini] and arr[i]
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n]; // variable length array

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
