#include <stdio.h>

#define VALUE_MASK 0x0F // Hex 0x0F, Decimal 15
                        // Binary 0000 1111
#define SUIT_MASK 0x30  // 0x30 is a hexadecimal
                        // constant (decimal 48)
                        // (which equals 00110000 in binary)

int isSameSuit(char card1, char card2)
{
    return (card1 & SUIT_MASK) == (card2 & SUIT_MASK);
}

int greaterValue(char card1, char card2)
{
    return ((unsigned char) (card1 & VALUE_MASK) >
            (unsigned char) (card2 & VALUE_MASK));
}

int main()
{
    char hand[5]; // represents a 5-card hand
    char card1, card2; // two cards to compare
    card1 = hand[0];
    card2 = hand[1];
    // ...

    if(isSameSuit(card1, card2))
    {
        
    }

    if(greaterValue(card1, card2))
    {

    }

    return 0;
}