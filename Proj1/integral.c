#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * CSE 251 Project 1
 * By: elivon
 *
 * Complete the following table:
 *
 * a b n estimate
 * −1 1 1883 1.178979838
 * 0 10 2028 0.489888070
 * −1000 1000 18861 0.999796418
 * 10 15 1515 0.016860599
 * 0.1 0.2 138 0.096211811
 *
 */
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

double f(double x);
double calIntegral(double a, double b, int n);

int main()
{
  double a, b; //积分起点、积分终点
  int n;       //分割份数
  double I_now, I_last, error;

  do
  {
    printf("Enter a value for a: ");
    scanf("%lf", &a);
    printf("Enter a value for b: ");
    scanf("%lf", &b);
  } while (a >= b);
  n = max((b - a) * 2, 10);

  // 1. Stop when n reaches 100000.
  // 2. Stop when the decrease in error becomes less than 1 × 10^−10.
  I_now = calIntegral(a, b, n);
  error = 10;
  printf("Integral evaluation\n");
  printf("%d: %.9lf\n", n, I_now);
  while (n < 100000 && error >= 1e-10)
  {
    I_last = I_now;
    n++;
    I_now = calIntegral(a, b, n);
    error = fabs(I_now - I_last);
    printf("%d: %.9lf %.6e\n", n, I_now, error);
  }
  printf("The integral result is %.9lf\n", I_now);
}
double f(double x)
{
  return x == 0 ? 1 : sin(M_PI * x) / (M_PI * x);
}

double calIntegral(double a, double b, int n)
{
  double integral = 0;
  double delta = (b - a) / n;
  integral = 0;
  for (int i = 0; i < n; i++)
  {
    integral += f(a + (i + 0.5) * delta);
  }
  integral *= delta;
  return integral;
}