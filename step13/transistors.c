#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "transistors.h"

/*
 * Name :  elivon
 * Description : Simple transistor description example program
 */

int main()
{
  int i;
  Tran *trans, *newtrans;
  int numTrans = 0;

  printf("transistors!\n");

  /* Allocate space for one transistor */
  trans = malloc(sizeof(Tran));
  numTrans = 1;
  /* Input the transistor */
  trans[0] = InputTransistor();

  while (InputYesOrNo("Would you like to enter another transistor (Y/N)? "))
  {
    /* Increase the space by one transistor */
    newtrans = realloc(trans, sizeof(Tran) * (numTrans + 1));
    if (newtrans)
    {
      trans = newtrans;
      numTrans++;
      trans[numTrans - 1] = InputTransistor();
    }
    else
    {
      printf("realloc fail!\n\n");
    }
  }
  /* Output the transistors */
  printf("\nThe transistors:\n");
  printf("------------------------------------\n");
  for (i = 0; i < numTrans; i++)
  {
    DisplayTransistor(trans[i]);
    printf("------------------------------------\n");
  }
  /* Free the memory */
  free(trans);
  system("pause");
}