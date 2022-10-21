#include <stdio.h>
#include <stdlib.h>

/*
 * Name : elivon
 * Program to experiment with arrays
 */

#define NumMovies 10
#define MaxGrosses 5
int main()
{
  double sum;
  int i, j, index;
  int highestGrossIndex = 0;
  double highestGross = 0;

  double gross[NumMovies] = {4633070, 3856195, 3171189, 1877685, 3251622,
                             3156594, 1629735, 2659234, 2028036, 510768};
  char *names[NumMovies] = {"Hall Pass", "Unknown", "I Am Number Four", "The King's Speech",
                            "Just Go With It", "Gnomeo and Juliet", "Drive Angry",
                            "Justin Beiber: Never Say Never", "Big Mommas: Like Father, Like Son",
                            "True Grit"};
  double maxGross[MaxGrosses] = {500000, 1000000, 2000000, 4000000, 10000000};

  sum = 0; /* Initialize to zero */
  for (i = 0; i < NumMovies; i++)
  {
    printf("Movie %2d %33s: %8.0f\n", i + 1, names[i], gross[i]);
    sum += gross[i];
  }
  printf("Total gross for these films was $%.0f\n", sum);

  highestGross = 0;
  highestGrossIndex = -1;
  for (i = 0; i < NumMovies; i++)
  {
    if (gross[i] > highestGross)
    {
      highestGrossIndex = i;
      highestGross = gross[highestGrossIndex];
    }
  }
  printf("The highest grossing film is: %s\n", names[highestGrossIndex]);

  for (index = 0; index < MaxGrosses; index++)
  { // with the max gross limited,find the highest gross
    highestGross = 0;
    highestGrossIndex = -1;
    for (i = 0; i < NumMovies; i++)
    {
      if (gross[i] > highestGross && gross[i] < maxGross[index])
      {
        highestGrossIndex = i;
        highestGross = gross[highestGrossIndex];
      }
    }
    if (highestGrossIndex < 0)
    {
      printf("No film made less than %.0f\n", maxGross[index]);
    }
    else
    {
      printf("The highest gross less than %.0f is %s at %d\n",
             maxGross[index], names[highestGrossIndex], highestGrossIndex + 1);
    }
  }
}