//Including libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Define symbols
#if defined(_WIN32) || defined(__MSDOS__)
	#define SPADE   "\x06"
	#define CLUB    "\x05"
	#define HEART   "\x03"
	#define DIAMOND "\x04"
#else
	#define SPADE   "\xE2\x99\xA0"
	#define CLUB    "\xE2\x99\xA3"
	#define HEART   "\xE2\x99\xA5"
	#define DIAMOND "\xE2\x99\xA6"
#endif

#define max_row 14;
#define max_col 4;
#define CitimValoare(v) scanf("%d",&v);

//Alocating memory for every card
void AlocateMemory(char **Deck)
{
	int col,row;
	for (row = 0; row < 4; row++)
		for (col = 0; col < 14; col++)
		{
			*(Deck+row*4+col) = (char)malloc(4 * sizeof(char));
		}
}

//Function created for creating special numbers
int CheckNumber(int number)
{
	int k;
	k = 0;
	if (number >= 9 && number <= 13)
		k = 1;
	return k;
}

//Creating special numbers (A,J,Q,K)
void SpecialNumbers(char *Number, int col)
{
	if (col + 2 == 11)
		strcpy(Number, "A");
	else if (col + 2 == 12)
		strcpy(Number, "J");
	else if (col + 2 == 13)
		strcpy(Number, "Q");
	else if (col + 2 == 14)
		strcpy(Number, "K");
}

//Refilling the Deck
void DeckRefill(char **Deck)
{
	int row, col;
	char Number[5];
	for (row = 0; row < 4; row++)
		{
			if (row == 0)
			{
				for (col = 0; col < 13; col++)
				{
					if (!CheckNumber(col))
					{
						sprintf(Number, "%d", col + 2);
						strcat(Number, SPADE);
						strcpy((Deck + row * 13 + col), Number);
					}
					else
					{
						SpecialNumbers(Number, col);
						strcat(Number, SPADE);
						strcpy((Deck + row * 13 + col), Number);
					}
				}
			}
			if (row == 1)
			{
				for (col = 0; col < 13; col++)
				{
					if (!CheckNumber(col))
					{
						sprintf(Number, "%d", col + 2);
						strcat(Number, CLUB);
						strcpy((Deck + row * 13 + col), Number);
					}
					else
					{
						SpecialNumbers(Number, col);
						strcat(Number, CLUB);
						strcpy((Deck + row * 13 + col), Number);
					}
				}
			}
			if (row == 2)
			{
				for (col = 0; col < 13; col++)
				{
					if (!CheckNumber(col))
					{
						sprintf(Number, "%d", col + 2);
						strcat(Number, HEART);
						strcpy((Deck + row * 13 + col), Number);
					}
					else
					{
						SpecialNumbers(Number, col);
						strcat(Number, HEART);
						strcpy((Deck + row * 13 + col), Number);
					}
				}
			}
			if (row == 3)
			{
				for (col = 0; col < 13; col++)
				{

					if (!CheckNumber(col))
					{
						sprintf(Number, "%d", col + 2);
						strcat(Number, DIAMOND);
						strcpy((Deck + row * 13 + col), Number);
					}
					else
					{
						SpecialNumbers(Number, col);
						strcat(Number, DIAMOND);
						strcpy((Deck + row * 13 + col), Number);
					}
				}
			}
		}
}  



int main()
{
	int row, col;
	char **Deck;
	//Alocating memory for all deck
	Deck = (char **)malloc(4 * 13 * sizeof(char*));
	AlocateMemory(Deck);
	DeckRefill(Deck);
	for (row = 0; row < 4; row++)
	{
		for (col = 0; col < 13; col++)
		{
			printf("%s ", (Deck + row * 13 + col));
		}
		printf("\n");
	}
	return 0;
}