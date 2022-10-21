#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
 * Name : elivon
 * Program to draw playing cards
 */
void PrintCard(int card, int suit);
int CompareCard(int card1, int suit1, int card2, int suit2);
int main()
{
  // int suit, card;
  int suit1, card1, suit2, card2;
  int winner;
  /*
   . This seeds the random number
   . generator with the current time
   */
  srand(time(NULL));

  printf("[Player 1]: ");
  suit1 = rand() % 4;
  card1 = rand() % 13 + 1;
  PrintCard(card1, suit1);

  printf("\t\t[Player 2]: ");
  do
  {
    suit2 = rand() % 4;
    card2 = rand() % 13 + 1;
  } while (card1 == card2 && suit1 == suit2);
  PrintCard(card2, suit2);
  printf("\n");

  winner = CompareCard(card1, suit1, card2, suit2);
  if (winner != 0)
    printf("Player %d wins\n\n", winner);
  else
    printf("There is a tie\n\n");
}

void PrintCard(int card, int suit)
{
  switch (suit)
  {
  case 0:
    printf("Hearts");
    break;
  case 1:
    printf("Diamonds");
    break;
  case 2:
    printf("Spades");
    break;
  case 3:
    printf("Clubs");
    break;
  }
  printf("-");
  switch (card)
  {
  case 1:
    printf("A");
    break;
  case 11:
    printf("J");
    break;
  case 12:
    printf("Q");
    break;
  case 13:
    printf("K");
    break;
  default:
    printf("%d", card);
    break;
  }
}
int CompareCard(int card1, int suit1, int card2, int suit2)
{
  if (card1 == 1)
    card1 = 14;
  if (card2 == 1)
    card1 = 14;
  if (card1 != card2)
  {
    return card1 > card2 ? 1 : 2;
  }
  else
  {
    if (suit1 != suit2)
      return suit1 < suit2 ? 1 : 2;
    else
      return 0;
  }
}