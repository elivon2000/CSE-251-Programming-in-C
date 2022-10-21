#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main()
{
  int numSteps = 40;
  double maxAngle = M_PI * 2;
  double angle, sinVal, derivative;
  int i, spaceNum;

  do
  {
    printf("Input the number of steps: ");
    scanf("%d", &numSteps);
  } while (numSteps < 2);

  for (i = 0; i <= numSteps; i++)
  {
    angle = (double)i / (double)numSteps * maxAngle;
    sinVal = sin(angle);
    derivative = cos(angle);
    spaceNum = 30 + (int)(30 * sinVal + 0.5);

    printf("%3d: %5.2f", i, angle);
    for (int index = 0; index < spaceNum; index++)
      printf(" ");
    if (derivative >= 0.1)
      printf("\\\n");
    else if (derivative <= -0.1)
      printf("/\n");
    else
      printf("*\n");
  }
  return 0;
}
