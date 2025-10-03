#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= 1) {
        int mid = 1 + (r - 1) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return binarySearch(arr, 1, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    int x;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Enter 1-10: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, 9, x);

    if (result == -1)
    printf("Value %d not found.\n", x);
        else
    printf("Value %d found at index %d.\n", x, result);
    return 0;
}