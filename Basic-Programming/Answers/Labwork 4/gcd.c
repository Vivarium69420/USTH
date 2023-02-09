#include <stdio.h>
#include "gcd.h"
int gcd(int a, int b){
  int i, result;
  for (i = 1; i <= a && i <=b; i++)
  {
    if(a%i==0 && b%i==0)
    {
      result =i;
    }
  }
  return result;
}