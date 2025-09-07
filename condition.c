#include <stdio.h>

int main() {
    
    int score = 70;
    char grade = (score >= 70 ? 'S' : 'U');

    printf("Grade: %c", grade);


    return 0;
}