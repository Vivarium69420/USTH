#include <stdio.h>
#include "gcd.c"
#include "gcd2.c"
#include "f(x).c"
#include "g(x).c"
#include "factorial.c"
#include "power.c"
// // Ex1:
// int gcd(int a, int b);
// int main(){
//   int a, b, result;
//   printf("Enter two positive integer: ");
//   scanf("%d%d", &a,&b);
//   result  = gcd(a,b);
//   printf("%d", result);
// }

// Ex2:
// int gcd2(int a, int b, int c, int d);
// int gcd(int a, int b);
// int main(){
//   int a,b,c,d, result;
//   int res1, res2, res3;
//   printf("Enter four positive integers: ");
//   scanf("%d%d%d%d",&a,&b,&c,&d);
  // result = gcd2(a,b,c,d);
  // res1 = gcd(a,b);
  // res2 = gcd(c,d);
  // res3 = gcd(res1, res2);
  // printf("%d", res3);
  // printf("%d", result);
// }

// // Ex3:
// double f_x(int a);
// int g_x(int a, int b);
// int main(){
//   int a,b, res2;
//   double res1;
//   printf("Please enter value for x and y: ");
//   scanf("%d%d", &a,&b);
//   res1 = f_x(a);
//   res2 = g_x(a,b);
//   printf("The value for f(x)=2.5x is: %f\n The value for g(x)=xy is: %d", res1, res2);
// }

// Ex4:
int factorial(int a);
int main(){
  int a, res;
  printf("Please enter a number: ");
  scanf("%d", &a);
  res = factorial(a);
  printf("%d", res);
  return 0;
}

// // Ex5:
// int power(int a, int size);
// int main(){
//   int a, size, res;
//   printf("Enter a number: ");
//   scanf("%d",&a);
//   printf("Enter the power: ");
//   scanf("%d",&size);
//   res = power(a,size);
//   printf("%d",res);
// }

