#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Name : elivon
 * Program to determine combinations
 */

int Binomial(int n, int k);

int main()
{
  int n;
  int k;
  int b;

  printf("Input n: ");
  scanf("%d", &n);
  if (n < 1)
  {
    printf("Must be greater than zero\n");
    exit(1);
  }

  printf("Input k: ");
  scanf("%d", &k);
  if (k < 0 || k > n)
  {
    printf("Must be between 0 and %d\n", n);
    exit(1);
  }

  b = Binomial(n, k);
  printf("%d items taken %d ways is %d\n", n, k, b);
  return 0;
}

int Binomial(int n, int k)
{
  if (k == n || k == 0)
    return 1;
  else
    return Binomial(n - 1, k - 1) + Binomial(n - 1, k);
}