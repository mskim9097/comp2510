/**
 * Course: COMP 2510
 * Assignment: Assignment 3
 * Name: Minsu Kim
 * Student ID: A01424659
 * Date: 2025-11-23
 * Description: A program that runs both projects
 * (Sorting Algorithm and Generics in C (Generic Swap Function))
 * from Assignment 3.
 */
#include <stdio.h>
#include <string.h>

// A support function that validates if input is integer.
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

// A support function that validates if input is float.
float validateFloat(const char *msg)
{
    float value;
    int ch;

    while (1)
    {
        printf("%s", msg);

        if (scanf("%f", &value) == 1)
        {
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            return value;
        }

        printf("Invalid float. Please try again.\n");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
}

// A support function for project 1 that prints an array.
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// A insertionSort function for project 1.
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

// A selectionSort function for project 1.
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

// Project 1 - Sorting Algorithm
void sortingAlgorithm()
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
        choice = validateInt("Enter choice (1-2): ");

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
}

// A swap function for Project 2.
void swap(void *a, void *b, size_t size)
{
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

// Project 2 - Generics in C (Generic Swap Function)
void genericSwap()
{
    int choice;
    while (1)
    {
        printf("Select data type to swap:\n");
        printf("1. Integer\n");
        printf("2. Float\n");
        printf("3. String\n");

        choice = validateInt("Enter choice (1-3): ");

        if (choice < 1 || choice > 3)
        {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
            continue;
        }
        break;
    }

    if (choice == 1)
    {
        int x = validateInt("Enter first integer: ");
        int y = validateInt("Enter second integer: ");

        printf("\nBefore swap: x = %d, y = %d\n", x, y);
        swap(&x, &y, sizeof(int));
        printf("After  swap: x = %d, y = %d\n", x, y);
    }
    else if (choice == 2)
    {
        float x = validateFloat("Enter first float: ");
        float y = validateFloat("Enter second float: ");

        printf("\nBefore swap: x = %.2f, y = %.2f\n", x, y);
        swap(&x, &y, sizeof(float));
        printf("After  swap: x = %.2f, y = %.2f\n", x, y);
    }
    else if (choice == 3)
    {
        char s1[100];
        char s2[100];

        printf("Enter first string: ");
        if (fgets(s1, sizeof(s1), stdin) == NULL)
        {
            printf("Input error.\n");
            return;
        }

        printf("Enter second string: ");
        if (fgets(s2, sizeof(s2), stdin) == NULL)
        {
            printf("Input error.\n");
            return;
        }

        s1[strcspn(s1, "\r\n")] = '\0';
        s2[strcspn(s2, "\r\n")] = '\0';

        printf("\nBefore swap: s1 = \"%s\", s2 = \"%s\"\n", s1, s2);
        swap(s1, s2, sizeof(s1));
        printf("After  swap: s1 = \"%s\", s2 = \"%s\"\n", s1, s2);
    }
    else
    {
        printf("Invalid choice.\n");
    }
}

// A drive program that displays menu to call functions.
int main(void)
{
    int input;

    while (1)
    {
        printf("\n=== COMP 2510 Assignment 3 Menu ===\n");
        printf("1) Project 1 - Sorting Algorithm\n");
        printf("2) Project 2 - Generics in C (Generic Swap Function)\n");
        printf("3) Quit\n");

        input = validateInt("Enter choice (1-3): ");

        switch (input)
        {
            case 1:
                sortingAlgorithm();
                break;
            case 2:
                genericSwap();
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Choose 1-3.\n");
                break;
        }
    }

    return 0;
}