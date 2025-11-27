#include <stdio.h>
#include <string.h>

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

void swap(void *a, void *b, size_t size)
{
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int main(void)
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
            return 1;
        }

        printf("Enter second string: ");
        if (fgets(s2, sizeof(s2), stdin) == NULL)
        {
            printf("Input error.\n");
            return 1;
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

    return 0;
}