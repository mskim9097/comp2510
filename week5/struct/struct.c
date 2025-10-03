#include <stdio.h>

struct line {
    int x1, y1;
    int x2, y2;
};

typedef struct {
    int x3, y3;
    int x4, y4;
} line_t;

int main()
{
    struct line line1;

    line1.x1 = 0;
    line1.y1 = 0;
    line1.x2 = 5;
    line1.y2 = 10;

    printf("(%d, %d), (%d, %d)\n", line1.x1, line1.y1, line1.x2, line1.y2);

    line_t line2;

    line2.x3 = 0;
    line2.y3 = 0;
    line2.x4 = 10;
    line2.y4 = 5;

    printf("(%d, %d), (%d, %d)\n", line2.x3, line2.y3, line2.x4, line2.y4);


    return 0;
}