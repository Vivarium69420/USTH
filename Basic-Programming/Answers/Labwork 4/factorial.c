#include <stdio.h>
#include "factorial.h"

// // non-recursive
// int factorial(int a){
//   int res=1;
//   for (int i = 1; i <= a; i++)
//   {
//     res = res*i;
//   }
//   printf("%d", res);
// }

// recursive
int factorial(int a){
  if(a==0)
    return (1);
  return(a*factorial(a-1));
}