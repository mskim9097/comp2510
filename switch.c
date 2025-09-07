#include <stdio.h>

int main() {

    int month = 2;
    int days;

    switch (month)
    {
    case 2:
        days = 28;
        break;
    case 9:
    case4:
    case 6:
    case 11:
        days = 30;
        break;
    default:
        days = 31;
        break;
    }

    printf("%d", days);

    return 0;
}