#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Name: elivon
*/
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main()
{
  int L, C;
  double F, sqrt_LC;

  printf("Input Capacitance (microfarads): ");
  scanf("%d", &C);
  printf("Input Inductance (millihenrys): ");
  scanf("%d", &L);

  sqrt_LC = sqrt((double)L / 1000 * (double)C / 1000000);
  F = (1 / sqrt_LC) / (2 * M_PI);
  printf("Resonant Frequency is %.3f\n", F);

  return 0;
}