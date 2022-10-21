#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

/*
 * Simple lunar lander program.
 * By:  elivon
 * Best landing: Time = 13 seconds, Fuel = 87.9, Velocity = -2.99
 */
int main()
{
  double altitude = 100; /* Meters */
  double velocity = 0;   /* Meters per second */
  double fuel = 100;     /* Kilograms */
  double power = 1.5;    /* Acceleration per pound of fuel */
  double g = -1.63;      /* Moon gravity in m/s^2 */
  double burn;           /* Amount of fuel to burn */
  bool valid;            /* Valid data entry flag */
  int seconds = 0;
  printf("Lunar Lander - (c) 2012, by elivon\n");

  while (altitude > 0)
  {
    printf("Time = %d seconds, Altitude = %.2f, Velocity = %.2f, Fuel = %.1f\n",
           seconds, altitude, velocity, fuel);
    do
    {
      valid = false;
      printf("How much fuel would you like to burn: ");
      scanf("%lf", &burn);
      if (burn < 0)
      {
        printf("You can't burn negative fuel\n");
      }
      else if (burn > fuel)
      {
        printf("You can't burn fuel you don't have\n");
      }
      else if (burn > 5)
      {
        printf("You can burn no more than 5 kilograms\n");
      }
      else
      {
        // printf("Burning %.1f kilograms of fuel\n", burn);
        valid = true;
      }
    } while (!valid);
    velocity = velocity + g + power * burn;
    altitude += velocity;
    fuel -= burn;
    seconds++;
  }
  printf("Time = %d seconds, Fuel = %.1f, Velocity = %.2f\n", seconds, fuel, velocity);
  if (fabs(velocity) > 3)
  {
    printf("Your next of kin have been notified\n");
  }
}