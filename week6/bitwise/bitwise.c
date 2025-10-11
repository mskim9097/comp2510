#include <stdio.h>

int thirdBitFromRight(int n)
{
    int mask = 4;
    return (n & mask) == 4;
}
void runTest1(int n)
{
    printf("n = %d, thirdBitFromRight = %d\n", n,
           thirdBitFromRight(n));
}

int turnOnThirdBit(int n)
{
    int mask = 4; // 0000010 - third bit from right
    return n | mask; // Turn it ON using bitwise OR
}

void runTest2(int n)
{
    printf("n = %d -> after turning on 3rd bit = %d\n", n, turnOnThirdBit(n));
}

//Function to turn ON the 1st and 3rd bits from the right
int turnOnFirstAndThirdBits(int n)
{
    int mask = 5; // Binary: 00000101 -> bits 0 and 2 are 1
    return n | mask;
}

void runTest3(int n)
{
    printf("n = %d -> after turning on 1st and 3rd bits = %d\n", n, turnOnFirstAndThirdBits(n));
}

int main()
{
    runTest1(4);
    runTest1(15);
    runTest1(0);
    runTest1(11);

    runTest2(2); // 00000010 will turn to 00000110 (which is 6)

    runTest3(0);
    runTest3(8);

    return 0;
}