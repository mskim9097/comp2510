#include <stdio.h>

int validateInt(const char *msg)
{
    int value;
    int ch;

    while (1)
    {
        printf("%s", msg);

        if (scanf("%d", &value) == 1)
        {
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            return value;
        }

        printf("Invalid integer. Please try again.\n");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

/* -------- Insertion Sort -------- */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j   = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

/* -------- Selection Sort -------- */
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp      = arr[i];
            arr[i]        = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main(void)
{
    int n;

    while (1)
    {
        n = validateInt("Enter number of elements: ");
        if (n > 0)
            break;

        printf("Number of elements must be positive.\n");
    }

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        char msg[50];
        sprintf(msg, "Element %d: ", i + 1);
        arr[i] = validateInt(msg);
    }

    printf("\nUnsorted array: ");
    printArray(arr, n);

    printf("\nChoose sorting algorithm:\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");

    int choice;
    while (1)
    {
        choice = validateInt("Choose sorting algorithm (1=Insertion, 2=Selection): ");

        if (choice == 1 || choice == 2)
            break;

        printf("Invalid choice. Please enter 1 or 2.\n");
    }

    /* copy original array */
    int sorted[n];
    for (int i = 0; i < n; i++)
    {
        sorted[i] = arr[i];
    }

    if (choice == 1)
    {
        insertionSort(sorted, n);
        printf("\nSorted using Insertion Sort: ");
    }
    else
    {
        selectionSort(sorted, n);
        printf("\nSorted using Selection Sort: ");
    }

    printArray(sorted, n);
    printf("\n");

    return 0;
}