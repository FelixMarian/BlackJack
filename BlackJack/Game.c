//Including libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
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

//Bold
#define BOLD_ON  "\e[1m"
#define BOLD_OFF   "\e[m"


#define max_row 14;
#define max_col 4;
#define Read(v) scanf("%d",&v);
#define PrintAndRead(m,v) printf(m); scanf("%d",&v);
#define Wait(v) Sleep(v);



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

//An simple animation for option 2
void RefillingAnimation()
{
	int i;
	for (i = 0; i < 3; i++)
	{
		printf("\r                                          ");
		printf("\rThe deck and credits are refilling.");
		Wait(500);
		printf("\r                                          ");
		printf("\rThe deck and credits are refilling..");
		Wait(500);
		printf("\r                                          ");
		printf("\rThe deck and credits are refilling...");
		Wait(500);
		printf("\r                                          ");
	}
		printf("\rCongratulations! The deck and credits has been succesfully refilled.");
		Wait(500);
		printf("\r                                                                      ");
		printf("\rChoose your option: ");
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

//Refilling the Credit with 5000
int CreditRefill(int *credit)
{
	credit = 5000;
	return credit;
}


void createMenu(int credit)
{
	printf("   \n\n              -------------------------------------------------------------------------------------------\n");
	printf("              |     Options:                                                                            |\n");
	printf("              |     0. Exit                                                        Credits:             |\n");
	printf("              |     1. Play                                                          %d               |\n", credit);
	printf("              |     2. Refill credits and deck                                                          |\n");
	printf("              -------------------------------------------------------------------------------------------\n\n");
	printf("Choose your option: ");
}

int main()
{
	int row, col, credits=0;
	char **Deck;
	char opt;
	//Alocating memory for all deck
	Deck = (char **)malloc(4 * 13 * sizeof(char*));
	AlocateMemory(Deck);
	DeckRefill(Deck);
	credits = CreditRefill(credits);
	//Main menu
	createMenu(credits);
	do
	{
		scanf("%s", &opt);
		switch (opt)
		{
		case '0':
			free(Deck);
			exit(0);
			break;
		case '1':
			break;
		case '2':
			system("cls");
			createMenu(credits);
			RefillingAnimation();
			credits = CreditRefill(credits);
			DeckRefill(Deck);
			system("cls");
			createMenu(credits);
			break;
		default:
			printf("This option doesn`t exist.\n");
			break;
		}
	} while (1);
	system("pause");
	return 0;
}