#include <stdio.h>

void copy_arr(double target[], double source[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        target[i] = source[i];
    }
}
void copy_ptr(double *target, double *source, int n)
{
    for(int i = 0; i < n; ++i)
    {
        *(target + i) = *(source + i);
    }
}

void copy_ptrs(double *target, double *source, double *end)
{
    while (source < end)
    {
        *target++ = *source++;
    }
}



int main()
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);

    printf("source : ");
    for (int i = 0; i < 5; ++i)
        printf("%.1f ", source[i]);
    printf("\n");

    printf("target1: ");
    for (int i = 0; i < 5; ++i)
        printf("%.1f ", target1[i]);
    printf("\n");

    printf("target2: ");
    for (int i = 0; i < 5; ++i)
        printf("%.1f ", target2[i]);
    printf("\n");

    printf("target3: ");
    for (int i = 0; i < 5; ++i)
        printf("%.1f ", target3[i]);
    printf("\n");

    return 0;
}