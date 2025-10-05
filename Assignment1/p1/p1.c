#include <stdio.h>

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
        else
        {
            printf("Invalid input. Download speed must be a positive number\n");
            while (getchar() != '\n');
        }
    }
    
    while(1)
    {
        printf("\nEnter Size of a file (MB): ");
        if(scanf("%f", &fileSizeMb) == 1 && fileSizeMb > 0)
        {
            break;
        }
        else
        {
            printf("Invalid input. File size must be a positive number\n");
            while (getchar() != '\n');
        }

    }

    downloadTimeSec = (fileSizeMb * 8.0f) / downloadSpeedMbps;

    printf("At %.2f megabits per second, a file of %.2f megabytes downloads in %.2f seconds\n", 
        downloadSpeedMbps, fileSizeMb, downloadTimeSec);

}

int main()
{
    downloadTime();
    return 0;
}