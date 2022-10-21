#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Name:elivon
 */

int main()
{
  /*
  Enter your annual income: 75000
  What is your filing status?
  1) single
  2) married filing jointly
  3) married filing separately
  Please enter a number: 2
  How many children do you have? 3
  5965.00
  */
  enum Filing
  {
    single = 1,
    jointly,
    separately
  };
  enum Filing filing_status;
  double income, deductions, taxable_income, tax;
  int children;
  printf("Enter your annual income: ");
  scanf("%lf", &income);
  if (income <= 0)
  {
    printf("Your income is less than 0!");
    exit(1);
  }
  if (income <= 9350)
  {
    printf("You don't need to pay tax.");
    exit(0);
  }
  printf("What is your filing status?\n");
  printf("1) single\n");
  printf("2) married filing jointly\n");
  printf("3) married filing separately\n");
  printf("Please enter a number: ");
  scanf("%u", &filing_status);
  if (!(filing_status >= 1 && filing_status <= 3))
  {
    printf("Your enter a wrong filing status!");
    exit(1);
  }
  if (filing_status == jointly)
  {
    printf("How many children do you have? ");
    scanf("%d", &children);
    if (!(children >= 0 && children <= 100))
    {
      printf("Your enter of children number is wrong!");
      exit(1);
    }
  }
  switch (filing_status)
  {
  case single:
    deductions = 5700 + 3650;
    break;
  case jointly:
    deductions = 5700 * 2 + 3650 * (2 + children);
    break;
  case separately:
    deductions = 5700 + 3650;
    break;
  default:
  {
    printf("Your enter a wrong filing status!");
    exit(1);
  }
  }
  taxable_income = income - deductions;
  if (taxable_income <= 0)
    tax = 0;
  else if (taxable_income > 0 && taxable_income <= 16750)
    tax = 0 + taxable_income * 0.1;
  else if (taxable_income > 16750 && taxable_income <= 68000)
    tax = 1675 + (taxable_income - 16750) * 0.15;
  else if (taxable_income > 68000 && taxable_income <= 137300)
    tax = 9362.5 + (taxable_income - 68000) * 0.25;
  else if (taxable_income > 137300)
    tax = 26687.5 + (taxable_income - 137300) * 0.28;
  else
  {
    printf("Unknow error in taxable_income!");
    exit(1);
  }
  printf("Your tax is %.2lf\n", tax);

  return 0;
}