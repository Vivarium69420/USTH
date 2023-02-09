#include <stdio.h>
#include "gcd2.h"
int gcd2(int a, int b, int c, int d){
  int i, result;
  for (i = 1; i <= a && i <=b && i <=c && i <=d; i++)
  {
    if(a%i==0 && b%i==0 && c%i==0 && d%i==0)
    {
      result =i;
    }
  }
  return result;
}