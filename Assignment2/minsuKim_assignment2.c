/**
 * Course: COMP 2510
 * Assignment: Assignment 2
 * Name: Minsu Kim
 * Student ID: A01424659
 * Date: 2025-10-29
 * Description: A program that runs both projects
 * (Bitwise Operations and Recursion)
 * from Assignment 2.
 */
#include <stdio.h>

#define MIN_VALUE -128
#define MAX_VALUE 127
#define MASK 0x0A

// A support function for project 1 that checks if second and fourth bits are ON.
int areSecondAndFourthBitsOn(int n)
{
    return ((n & MASK) == MASK) ? 1 : 0;
}

// A support function for project 1 that prints the 8-bit binary of input.
void printEightBitsBinary(int n)
{
    unsigned char u = (unsigned char)n;
    printf("Binary: ");
    for (int i = 7; i >= 0; --i)
    {
        putchar((u >> i) & 1 ? '1' : '0');
    }
    putchar('\n');
}

// A recursive function that calculates sum of digits.
int sumOfDigits(int n)
{
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

// Project 1 - Bitwise Operations
void bitwise()
{
    int n;

    while(1)
    {
        printf("\nEnter an integer: ");
        if(scanf("%d", &n) == 1)
        {
            if(n >= MIN_VALUE && n <= MAX_VALUE)
            {
                break;
            }
            else // validate range of input
            {
                printf("A value should be between %d and %d\n", MIN_VALUE, MAX_VALUE);
            }
        }
        else // validate input
        {
            printf("Invalid input.\n");
            while (getchar() != '\n'){} // clear input buffer
        }
    }
    printEightBitsBinary(n);
    
    if(areSecondAndFourthBitsOn(n))
    {
        printf("Second and fourth bits are ON.\n");
    }
    else
    {
        printf("Second and fourth bits are NOT both ON.\n");
    }
}

// Project 2 - Recursion
void recursion()
{
    int n;

    while(1)
    {
        printf("\nEnter a number: ");
        if(scanf("%d", &n) == 1)
        {
            if(n >= 0)
            {
                break;
            }
            else // validate positive number
            {
                printf("Please enter a positive number.\n");
            }
        }
        else // validate input
        {
            printf("Invalid input.\n");
            while (getchar() != '\n'){} // clear buffer
        }
    }
    printf("Sum of digits = %d\n", sumOfDigits(n));
}

// A drive program that displays menu to call functions.
int main(void)
{
    int input;

    while(1)
    {
        printf("\n=== COMP 2510 Assignment 2 Menu ===\n");
        printf("1) Project 1 - Bitwise Operation\n");
        printf("2) Project 2 - Recursion\n");
        printf("3) Quit\n");
        printf("Select: ");

        if(scanf("%d", &input) != 1)
        {
            printf("Invalid input. Please enter a number 1-3.\n");
            while(getchar() != '\n'){} // clear input buffer
            continue;
        }
        while(getchar() != '\n'){} // clear input buffer

        switch(input)
        {
            case 1:
                bitwise();
                break;
            case 2:
                recursion();
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