/**
 * Course: COMP 2510
 * Assignment: Assignment 1
 * Name: Minsu Kim
 * Student ID: A01424659
 * Date: 2025-10-04
 * Description: A program that runs all four projects
 * (Download Time, Height Converter, Sum of Squares, and Array Copy)
 * from Assignment 1.
 */
#include <stdio.h>

// Project 1 - Download Time
void downloadTime()
{
    float downloadSpeedMbps;
    float fileSizeMb;
    float downloadTimeSec;

    while(1)
    {
        printf("\nEnter download speed (Mb/s): ");
        if(scanf("%f", &downloadSpeedMbps) == 1 && downloadSpeedMbps > 0)
        {
            break;
        }
        else // validate input
        {
            printf("Invalid input. Download speed must be a positive number\n");
            while (getchar() != '\n'); // clear input buffer
        }
    }
    
    while(1)
    {
        printf("\nEnter Size of a file (MB): ");
        if(scanf("%f", &fileSizeMb) == 1 && fileSizeMb > 0)
        {
            break;
        }
        else // validate input
        {
            printf("Invalid input. File size must be a positive number\n");
            while (getchar() != '\n'); // clear input buffer
        }

    }

    downloadTimeSec = (fileSizeMb * 8.0f) / downloadSpeedMbps;

    printf("At %.2f megabits per second, a file of %.2f megabytes downloads in %.2f seconds\n", 
        downloadSpeedMbps, fileSizeMb, downloadTimeSec);

}

// Project 2 - Height Converter
void convertLength()
{
    float cm;
    float totalInches;
    int feet;
    float inches;
    int firstPrompt = 1;

    while(1)
    {
        if (firstPrompt)
        {
            printf("Enter a height in centimeters: ");
            firstPrompt = 0;
        }
        else
        {
            printf("Enter a height in centimeters (<=0 to quit): ");
        }

        if(scanf("%f", &cm) != 1) // validate input
        {
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        if (cm <= 0)
        {
            printf("bye\n");
            break;
        }

        totalInches = cm / 2.54f;
        feet = (int)(totalInches / 12);
        inches = totalInches - (feet * 12);

        printf("%.1f cm = %d feet, %.1f inches\n", cm, feet, inches);
    }
}

// Project 3 - Sum of Squares
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

        if (scanf("%d %d", &lower, &upper) != 2) // validate input
        {
            while (getchar() != '\n'); // clear input buffer
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

// Project 4 - Array Copy

// copy array using array notation
void copy_arr(double target[], double source[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        target[i] = source[i];
    }
}
// copy array using pointer notation and pointer incrementing
void copy_ptr(double *target, double *source, int n)
{
    for(int i = 0; i < n; ++i)
    {
        *(target + i) = *(source + i);
    }
}
// copy array using pointer notation and end pointer
void copy_ptrs(double *target, double *source, double *end)
{
    while (source < end)
    {
        *target++ = *source++;
    }
}

// A drive program that displays menu to call functions.
int main(void)
{
    int input;

    while(1)
    {
        printf("\n=== COMP 2510 Assignment 1 Menu ===\n");
        printf("1) Project 1 - Download Time\n");
        printf("2) Project 2 - Height Converter\n");
        printf("3) Project 3 - Sum of Squares\n");
        printf("4) Project 4 - Array Copy\n");
        printf("5) Quit\n");
        printf("Select: ");

        if(scanf("%d", &input) != 1)
        {
            printf("Invalid input. Please enter a number 1-5.\n");
            while(getchar() != '\n'); // clear input buffer
            continue;
        }
        while(getchar() != '\n'); // clear input buffer

        switch(input)
        {
            case 1:
                downloadTime();
                break;
            case 2:
                convertLength();
                break;
            case 3:
                sumOfSquares();
                break;
            case 4:
            {
                double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
                double target1[5];
                double target2[5];
                double target3[5];

                // invoke copy functions
                copy_arr(target1, source, 5);
                copy_ptr(target2, source, 5);
                copy_ptrs(target3, source, source + 5);

                // display original array and copied arrays
                printf("source (original): ");
                for (int i = 0; i < 5; ++i)
                    printf("%.1f ", source[i]);
                printf("\n");

                printf("target1 (copied by array notation): ");
                for (int i = 0; i < 5; ++i)
                    printf("%.1f ", target1[i]);
                printf("\n");

                printf("target2 (copied by pointer incrementing): ");
                for (int i = 0; i < 5; ++i)
                    printf("%.1f ", target2[i]);
                printf("\n");

                printf("target3 (copied by end pointer): ");
                for (int i = 0; i < 5; ++i)
                    printf("%.1f ", target3[i]);
                printf("\n");
                break;
            }
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Choose 1-5.\n");
                break;
        }
    }

    return 0;
}