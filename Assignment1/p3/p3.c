#include <stdio.h>

void sumOfSquares()
{
    int lower, upper;
    long sum;
    int firstPrompt = 1;

    while(1)
    {
        if (firstPrompt)
        {
            printf("Enter lower and upper integer limits: ");
        }
        else
        {
            printf("Enter next set of limits: ");
        }

        if (scanf("%d %d", &lower, &upper) != 2)
        {
            while (getchar() != '\n');
            continue;
        }

        firstPrompt = 0;

        if(upper <= lower)
        {
            printf("Done\n");
            break;
        }

        sum = 0;
        for(int i = lower; i <= upper; ++i)
        {
            sum += (long)i * i;
        }

        printf("The sums of the squares from %d to %d is %ld\n", 
            lower * lower, upper * upper, sum);
    }
}

int main()
{
    sumOfSquares();
    return 0;
}