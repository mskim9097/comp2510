#include <stdio.h>
#include <string.h>

// What if we could write one function to swap two values of any single type?
void swap(void *data1ptr, void *data2ptr, size_t nbytes)
{
    char temp[nbytes];
    // store a copy of data1 in temporary storage
    memcpy(temp, data1ptr, nbytes);
    // copy data2 to location of data1
    memcpy(data1ptr, data2ptr, nbytes);
    // copy data in temporary storage to location of data2
    memcpy(data2ptr, temp, nbytes);
}

int main(int argc, char *argv[]) 
{
    int x = 2;
    int y = 5;
    //short x = 2;
    //short y = 5;
    //char *x = "2";
    //char *y = "5";
    //mystruct x = {…};
    //mystruct y = {…};

    swap(&x, &y, sizeof(x));
    // want x = 5, y = 2
    printf("x = %d, y = %d\n", x, y);
    return 0;
}

// void swap_int(int *a, int *b) 
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// int main(int argc, char *argv[]) 
// {
//     int x = 2;
//     int y = 5;
//     swap_int(&x, &y);
//     // want x = 5, y = 2
//     printf("x = %d, y = %d\n", x, y);
//     return 0;
// }

// void swap_short(short *a, short *b) {
//     short temp = *a;
//     *a = *b;
//     *b = temp;
// }
// int main(int argc, char *argv[]) {
//     short x = 2;
//     short y = 5;
//     swap_short(&x, &y);
//     // want x = 5, y = 2
//     printf("x = %d, y = %d\n", x, y);
//     return 0;
// }

// void swap_string(char **a, char **b) {
//     char *temp = *a;
//     *a = *b;
//     *b = temp;
// }
// int main(int argc, char *argv[]) {
//     char *x = "2";
//     char *y = "5";
//     swap_string(&x, &y);
//     // want x = 5, y = 2
//     printf("x = %s, y = %s\n", x, y);
//     return 0;
// }