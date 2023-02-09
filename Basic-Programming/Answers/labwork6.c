#include <stdio.h>
#include <stdlib.h>
// void swap(int*a, int*b){
//   int t;
//   t = *a;
//   *a = *b;
//   *b = t;
// }

// int add(int* a, int* b){
//   int res;
//   res = *a + *b;
//   return res;
// }
// // Ex1
// int main(){
//   int a, b;
//   printf("Please enter a: ");
//   scanf("%d",&a);
//   printf("Please enter b: ");
//   scanf("%d",&b);
//   swap(&a,&b);
//   printf("a=%d\nb=%d",a,b);
// }

// // Ex2:
// int main(){
//   int a, b, res;
//   printf("Please enter a: ");
//   scanf("%d",&a);
//   printf("Please enter b: ");
//   scanf("%d",&b);
//   res = add(&a,&b);
//   printf("result = %d", res);
// }

// // Ex3:
int main(){
  int i, n;
  printf("Please enter array size: ");
  scanf("%d", &n);
  int A[n];
  for (i = 0; i < n; i++)
  {
    printf("Please enter your elements: ");
    scanf("%d",&A[i]);
  }
  
  for (i = 0; i < n; i++)
  {
    printf("%d\n", *(A+i));
  }
  return 0;
}

// // Ex4:
// int main(){
//   int n, i, *p;
//   printf("Please enter array size: ");
//   scanf("%d", &n);
//   p =(int*)malloc(n*sizeof(int));
//   if(p == NULL){
//     printf("Error! Memory cannot be allocated");
//     exit(0);
//   }
//   for ( i = 0; i < n; i++)
//   {
//     printf("Please enter elements: ");
//     scanf("%d", p+i);
//   }
//   for ( i = 0; i < n; i++)
//     printf("%d\n",*(p+i));
// }

// // Ex5
// int main(){
//   int a =2;
//   int *b;
//   int** p;
//   int* p[10];
//   printf("%d", p[10]);
// }

// // Ex6:
// int main(){
//   int a = 2, b =3;
//   int c= (*add)(&a,&b);
//   printf("%d", c);
// }
