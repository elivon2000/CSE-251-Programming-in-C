#include <stdio.h>
#include <stdlib.h>

/*
 * Name : <Insert name>
 * Program to experiment with hexadecimal
 * and pointers
 */

int main()
{
  int a = 0;
  int b = 5;
  int c = 0x2251;
  int *pA = &a;
  int *pB = &b;
  int *p;

  printf("%d: %x\n", a, a);
  printf("%d: %x\n", b, b);
  printf("%d: 0x%x\n", c, c);

  printf("Next experiment:\n");
  p = pA;
  *p = 22;
  p = pB;
  *p = 18;
  p = &b;
  *p = 108;
  *p = 108;
  p = pA;
  *p = 2;

  system("pause");
}