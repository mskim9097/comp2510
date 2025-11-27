#include <stdio.h>

int main()
{
    int key, y;
    int n = 10;
    int arr[] = { 2, 0, 3, 1, 9, 8, 7, 6, 5, 4 };

    for (int x = 1; x < n; x++)
    {
        key = arr[x];
        y = x - 1;
        while (y >= 0 && arr[y] > key)
        {
            arr[y + 1] = arr[y];
            y = y - 1;
        }
        arr[y + 1] = key;
    }

    return 0;
}