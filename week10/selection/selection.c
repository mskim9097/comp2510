#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int main()
{
    int y, min;
    int n = 10;
    int arr[] = { 8, 5, 7, 2, 9, 0, 4, 3, 6, 1};

    for (int x = 0; x < n-1; x++)
    {
        min = x;
        for (y = x + 1; y < n; y++)
        {
            if (arr[y] < arr[min])
            {
                min = y;
            }
        }
        swap(&arr[min], &arr[x]);
    }

    return 0;
}