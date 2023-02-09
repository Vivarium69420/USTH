#include <stdio.h>
# include <string.h>
// Ex1
// int main(){
//   int n;
//   printf("Please enter a number: ");
//   scanf("%d", &n);
//   for (int i = 1; i < n; i++)
//   {
//     if (n%i==0)
//     {
//       printf("%d",i);
//     }
//   }
// }

// Ex2
// int main(){
//   int i,j,n;
//   printf("Enter the number till which you want prime numbers\n");
//   scanf("%d",&n);
//   printf("Prime numbers are:-\n");    
//   for(i=2;i<=n;i++)
//   {
//     int c=0;
//     for(j=1;j<=i;j++)
//     {
//       if(i%j==0)
//       {
//         c++;
//       }
//     }
//     if(c==2)
//     {
//       printf("%d ",i);
//     }
//   }
// }

// Ex3
int main(){
  int n;
  float sum = 0;
  printf("Please enter a number: ");
  scanf("%d", &n);
  for (float i = 1; i <= n; i++)
  {
    sum = sum +1/i;
  }
  printf("%f", sum);
}

// Ex4
// int main(){
  // int n, i = 1, result;
  // printf("Please enter a number: ");
  // scanf("%d", &n);
  // while (n!=0)
  // {
  //   result = n%10;
  //   i *= result;
  //   n /= 10;
  // }
  // printf("%d", i);
// }

// // Ex5:
// int main(){
//   int n,a=0, b=1, next;
//   next = a +b;
//   printf("Please enter a number: ");
//   scanf("%d", &n);
//   printf("%d, %d,",a,b);
//   for (int i = 3; i <=n; i++)
//   {
//     printf(" %d, ", next);
//     a = b;
//     b = next;
//     next = a +b;
//   }
// }

// // Ex6
// int main(){
//   int n, result =1;
//   printf("Please enter a number: ");
//   scanf("%d", &n);
//   for (int i = 1; i <= n; i++)
//   {
//     result = result * i;
//   }
//   printf("%d", result);
// }
  