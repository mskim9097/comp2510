#include <stdio.h>

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

        if(scanf("%f", &cm) != 1)
        {
            while (getchar() != '\n');
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

int main()
{
    convertLength();
    return 0;
}