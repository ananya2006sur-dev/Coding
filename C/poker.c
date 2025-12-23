/* A program to check for the probabilies of various hands in seven-card stud by Monte Carlo method */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum suit {hearts = 1, diamonds = 2, clubs = 3, spades = 4}; // Enumerated data type for suits of a card
typedef enum suit suit; // Defining a new data type suit

struct card // Structure to represent a card with pips and suit
{
	int pips;
	suit s;
};
typedef struct card card; // Defining a new data type card

void shuffle(card* deck) // Function to shuffle a deck of 52 cards
{
	for (int i = 0; i < 52; i++)
	{
		int j = rand() % 52; // Generating a random number between 0 and 51
		card temp = deck[i]; // Swapping the ith card with the jth card
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

void create_hand(card* hand) // Function to create a hand of five cards
{
	for (int i = 0; i < 5; i++)
	{
		(&hand[i])->pips = rand() % 13 + 1; // Assigning a random number between 1 and 13 to the pips of a card
		(&hand[i])->s = rand() % 4 + 1; // Assigning a random number between 1 and 4 to the suit of a card
	} 
}

int main()
{
    // Variables to store the number of each type of hand
	int royal_flush = 0;
	int straight_flush = 0;
	int four_of_a_kind = 0;
	int full_house = 0;
	int flush = 0;
	int straight = 0;
	int three_of_a_kind = 0;
	int two_pair = 0;
	int pair = 0;
	int ace_high_or_less = 0;

	
	
	for (int i = 1; i <= 10; i++) // Loop to generate 1 million hands
	{
        // Variables to store the number of each type of card in a hand
		int ace = 0;
		int two = 0;
		int three = 0;
		int four = 0;
		int five = 0;
		int six = 0;
		int seven = 0;
		int eight = 0;
		int nine = 0;
		int ten = 0;
		int jack = 0;
		int queen = 0;
		int king = 0;
		int heart = 0;
		int diamond = 0;
		int club = 0;
		int spade = 0;

		card* hand = malloc(5* sizeof(card)); // Allocating memory for a hand of five cards
		create_hand(hand);
		for (int j = 0; j < 5; i++) // Loop to count the number of each type of card in a hand
		{
			if ((&hand[j])->pips == 1)
			{
				ace++;
			}
			
			if ((&hand[j])->pips == 2)
			{
				two++;
			}

			if ((&hand[j])->pips == 3)
			{
				three++;
			}

			if ((&hand[j])->pips == 4)
			{
				four++;
			}

			if ((&hand[j])->pips == 5)
			{
				five++;
			}

			if ((&hand[j])->pips == 6)
			{
				six++;
			}

			if ((&hand[j])->pips == 7)
			{
				seven++;
			}

			if ((&hand[j])->pips == 8)
			{
				eight++;
			}

			if ((&hand[j])->pips == 9)
			{
				nine++;
			}

			if ((&hand[j])->pips == 10)
			{
				ten++;
			}

			if ((&hand[j])->pips == 11)
			{
				jack++;
			}

			if ((&hand[j])->pips == 12)
			{
				queen++;
			}

			if ((&hand[j])->pips == 13)
			{
				king++;
			}

			if ((&hand[j])->s == 1)
			{
				heart++;
			}

			if ((&hand[j])->s == 2)
			{
				diamond++;
			}

			if ((&hand[j])->s == 3)
			{
				club++;
			}

			if ((&hand[j])->s == 4)
			{
				spade++;
			}
        }
		
        // Variables to store the pips of each card in a hand
		int a = (&hand[0])->pips;
		int b = (&hand[1])->pips;
		int c = (&hand[2])->pips;
		int d = (&hand[3])->pips;
		int e = (&hand[4])->pips;
		
		// Checking for a flush (all cards of the same suit)
		if (heart == 5 || diamond == 5 || club == 5 || spade == 5) 
		{
			// Checking for a royal flush (A, K, Q, J, 10 of the same suit)
			if ((a == 1) && (b == 13) && (c == 12) && (d == 11) && (e == 10)) 
			{
				royal_flush++;
			}

			// Checking for a straight flush (five consecutive cards of the same suit)
			if ((b == a + 1) && (c == b + 1) && (d == c + 1) && (e == d + 1)) 
			{
				straight_flush++;
			}

			// If not a royal flush or a straight flush, it is a flush
			else 
			{
				flush++;
			}
		}
		
		// Checking for a straight (five consecutive cards of different suits)
		if ((b == a + 1) && (c == b + 1) && (d == c + 1) && (e == d + 1)) 
		{
			straight++;
		}

		// Checking for four of a kind (four cards of the same pips)
		if (ace == 4 || two == 4 || three == 4 || four == 4 || five == 4 || six == 4 || seven == 4 || eight == 4 || nine == 4 || ten == 4 || jack == 4 || queen == 4 || king == 4) 
		{
			four_of_a_kind++;
       	}

		// Checking for three of a kind (three cards of the same pips)
		if (ace == 3 || two == 3 || three == 3 || four == 3 || five == 3 || six == 3 || seven == 3 || eight == 3 || nine == 3 || ten == 3 || jack == 3 || queen == 3 || king == 3) 
		{
			// Checking for a full house (three cards of the same pips and two cards of the same pips)
			if (ace == 2 || two == 2 || three == 2 || four == 2 || five == 2 || six == 2 || seven == 2 || eight == 2 || nine == 2 || ten == 2 || jack == 2 || queen == 2 || king == 2) 
			{
				full_house++;
            }

			// If not a full house, it is a three of a kind
			else if (heart == 1 || diamond == 1 || club == 1 || spade == 1) 
			{
				three_of_a_kind++;
			}
		}

		// Checking for a pair (two cards of the same pips)
		if (ace == 2 || two == 2 || three == 2 || four == 2 || five == 2 || six == 2 || seven == 2 || eight == 2 || nine == 2 || ten == 2 || jack == 2 || queen == 2 || king == 2) 
		{
			// Checking for two pair (two cards of the same pips and two cards of the same pips)
			if (ace == 2 || two == 2 || three == 2 || four == 2 || five == 2 || six == 2 || seven == 2 || eight == 2 || nine == 2 || ten == 2 || jack == 2 || queen == 2 || king == 2) 
			{
				two_pair++;
			}

			// If not a two pair, it is a pair
			else 
			{
				pair++;
			}
		}

		// If none of the above, it is an ace high or less (no pair)
        else 
        {
            ace_high_or_less++;
        }
		
        free(hand);
		 
    }
	
    // Printing the number of each type of hand and their probabilities in a tabular format

	printf("%s\t%s\t%s\n", "Hand", "Combinations", "Probabilities"); // Printing field names of the table

    // Printing the data in the table
	
	printf("%s\t%d\t%llf\n", "Royal Flush", royal_flush, (long double)royal_flush/10);

	printf("%s\t%d\t%llf\n", "Straight Flush", straight_flush, (long double)straight_flush/10);

	printf("%s\t%d\t%llf\n", "Four of a kind", four_of_a_kind, (long double)four_of_a_kind/10);

	printf("%s\t%d\t%llf\n", "Full House", full_house, (long double)full_house/10);

	printf("%s\t%d\t%llf\n", "Flush", flush, (long double)flush/10);

	printf("%s\t%d\t%llf\n", "Straight", straight, (long double)straight/10);

	printf("%s\t%d\t%llf\n", "Three of a kind", three_of_a_kind, (long double)three_of_a_kind/10);

	printf("%s\t%d\t%llf\n", "Two Pair", two_pair, (long double)two_pair/10);

	printf("%s\t%d\t%llf\n", "Pair", pair, (long double)pair/10);

	printf("%s\t%d\t%llf\n", "Ace High or Less", ace_high_or_less, (long double)royal_flush/10);

	return 0;
}




