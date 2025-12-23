#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct card
    {
        int pips;
        char suit;
    };
    typedef struct card card;

    card c1;
    card* ptr_to_card;
    ptr_to_card = &c1;
    ptr_to_card->pips = 5; // (*ptr_to_card).pips = 5;
    ptr_to_card->suit = 'D'; //(*ptr_to_card).suit = 'D'
    printf("The card is the %d of %c\n", ptr_to_card->pips, ptr_to_card->suit);
}

