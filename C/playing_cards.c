#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* suitname(char suit)
{
    if (suit == 'C')
    {
        return "Clubs";
    }
    else if (suit == 'D')
    {
        return "Diamonds";
    }
    else if (suit == 'H')
    {
        return "Hearts";
    }
    else if (suit == 'S')
    {
        return "Spades";
    }
    else
    {
        return "Unknown";
    }
}

int main()
{
    struct card
    {
        int pips;
        char suit;
    };
    typedef struct card card;

    card c1;
    printf("Enter the suit of the card: ");
    scanf("%c", c1.suit);
    printf("The card is the %s\n", suitname(c1.suit));
}