#include <stdio.h>

void merge(int* result, int* left, int* right, int m, int n)
{
    int i1 = 0; // index into left side
    int i2 = 0; // index into right side

    for (int i = 0; i < m + n; i++) {
        if (i2 >= n || (i1 < m && left[i1] <= right[i2])) 
        {
            // take from left
            result[i] = left[i1];
            i1++;
        } 
        else 
        {
            // take from right
            result[i] = right[i2];
            i2++;
        }
    }
}

void mergeSort(int* arr, int n) {
    if (n > 1)
    {
        int mid = n / 2;
        int left[mid];
        int right[n - mid];

        for (int i = 0; i < mid; i++) 
        {
            left[i] = arr[i];
        }
        for (int i = mid; i < n; i++) 
        {
            right[i - mid] = arr[i];
        } 
        
        // recursively sort the two halves
        mergeSort(left, mid);
        mergeSort(right, n - mid);

        // Merge the two sorted halves
        merge(arr, left, right, mid, n - mid);
    }
}

int main()
{
    int arr[] = {8, 2, 9, 4, 5, 3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, n);

    printf("Sorted: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}