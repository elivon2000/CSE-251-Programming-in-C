#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*
 * Name:elivon
 * Simple program to experiment with looping
 */

int main()
{
  /*
  Number to compute the factorial of: 4
  4! = 24
  */
  int f = 0;   /* Number we compute the factorial of */
  int fac = 1; /* Initial value of factorial 0!=1*/
  int i;

  while (f >= 0)
  {
    printf("Number to compute the factorial of: ");
    scanf("%d", &f);
    if (f < 0)
    {
      printf("The number must be >= 0!\n");
    }
    else
    {
      i = f;
      fac = 1;
      while (i > 0)
      {
        fac = fac * i;
        i--;
      }
      printf("%d! = %d\n", f, fac);
    }
  }
  return 0;
}