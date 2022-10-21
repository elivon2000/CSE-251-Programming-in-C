#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*
 * Simple lunar lander program,find the best landing.
 * By:  elivon
 * Best landing: Time = 13 seconds, Fuel = 87.9, Velocity = -2.99
 */
const double g = -1.63;   /* Moon gravity in m/s^2 */
const double power = 1.5; /* Acceleration per pound of fuel */

bool checklive(double h, double v);
bool checklive_burn(double h, double v, double burn);
double findMinBurn(double h, double v);
int main()
{
  double altitude = 100; /* Meters */
  double velocity = 0;   /* Meters per second */
  double fuel = 100;     /* Kilograms */
  double burn;           /* Amount of fuel to burn */
  int seconds = 0;

  while (altitude > 0)
  {
    burn = findMinBurn(altitude, velocity);
    printf("Time = %d seconds, Altitude = %.2f, Velocity = %.2f, Fuel = %.1f, Burn = %.2f\n",
           seconds, altitude, velocity, fuel, burn);
    velocity = velocity + g + power * burn;
    altitude += velocity;
    fuel -= burn;
    seconds++;
  }
  printf("Best landing: \n");
  printf("Time = %d seconds, Altitude = %.2f, Velocity = %.2f, Fuel = %.1f\n\n",
         seconds, altitude, velocity, fuel);
  return 0;
}

bool checklive(double h, double v)
{
  // test the condition will crash or not
  while (h > 0 && v < 0)
  {
    v = v + g + 5 * power;
    h = h + v;
  }
  return v >= 0 || (h <= 0 && v > -3);
}
bool checklive_burn(double h, double v, double burn)
{
  v = v + g + burn * power;
  h = h + v;
  return checklive(h, v);
}
double findMinBurn(double h, double v)
{
  double low = 0, up = 5;
  double mid, ceil_low;
  if (checklive_burn(h, v, low))
    return low;
  else
  {
    while (up - low > 0.01)
    {
      // precision=0.01
      // up==>live low==>dead
      mid = 0.5 * (low + up);
      if (checklive_burn(h, v, mid))
        up = mid;
      else
        low = mid;
    }
    ceil_low = ceil(low * 100) / 100;
    return checklive_burn(h, v, ceil_low) ? ceil_low : ceil_low + 0.01;
  }
}