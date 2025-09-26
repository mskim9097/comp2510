#include <stdio.h>

long factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int x;
    printf("Enter number: ");
    scanf("%d", &x);
    int result = factorial(x);
    printf("%d", result);
    return 0;
}