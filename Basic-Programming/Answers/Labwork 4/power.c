#include <stdio.h>
#include "power.h"

// // recursive
// int power(int a, int size){
//   if(size==1)
//     return (a);
//   return(a*power(a,size-1));
// }

// non-recursive
int power(int a, int size){
  int res =1;
  if(size==1)
    return (a);
  while(size!=0)
  {
    res = res * a;
    --size;
  }
  return res;
}