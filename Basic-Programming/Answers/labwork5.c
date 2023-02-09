#include <stdio.h>
#include <stdlib.h>

// Ex1:

int main(){
  int n, i, *ptr, max, min;
  printf("Please number of element: ");
  scanf("%d", &n);
  ptr = (int*)malloc(n*sizeof(int));
  if(ptr == NULL){
    printf("Error! Memory not allocated.");
    exit(0);
  }
  for(i =0; i<n; ++i){
    printf("Enter elements: ");
    scanf("%d", ptr+i);
  }
  for (i = 1; i < n; i++)
  {
    max = *ptr;
    min = *ptr;
    if((*ptr+i)>max)
      max = *(ptr+i);
    if(*(ptr+i)<min)
      min =*(ptr+i);
  }
  printf("Largest number = %d", max);
  printf("Smallest number = %d", min);
  free(ptr);
  return 0;
}

// int main(){
//   int n, max, min, i;
//   printf("Please number of element: ");
//   scanf("%d", &n);
//   int arr[n];
//   for (i = 0; i < n; i++)
//   {
//     printf("Enter elements: ");
//     scanf("%d", &arr[i]);
//   }
//   for ( i = 0; i < n; i++)
//   {
//     min = arr[0];
//     max = arr[0];
//     if(arr[i]>min)
//       arr[i] = min;
//     if (arr[i]<max)
//       arr[i] = max;
//   }
//   printf("Max: %d; Min: %d", max, min);
// }

// // Ex2
// int main(){
//   int n, i, *ptr, sum_o=0, sum_e=0;
//   printf("Please number of element: ");
//   scanf("%d", &n);
//   ptr = (int*)malloc(n*sizeof(int));
//   if(ptr == NULL){
//     printf("Error! Memory not allocated.");
//     exit(0);
//   }
//   for (i = 1; i <= n; i++)
//   {
//     if(i%2==0){
//       printf("The even number are: %d\n",i);
//       sum_e+=i;
//     }
//     else{
//       printf("The odd number are: %d\n",i);
//       sum_o+=i;
//     }
//   }
//   printf("The sum of even number: %d\n", sum_e);
//   printf("The sum of odd number: %d", sum_o);
//   free(ptr);
//   return 0;
// }

// // Ex3:

// // Bubble sort
// int main(){
//   int n,i,j;
//   printf("Enter size of the array: ");
//   scanf("%d", &n);
//   int arr[n];
//   printf("Enter elements in array: ");
//   for (i = 0; i < n; i++)
//   {
//     scanf("%d", &arr[i]);
//   }
//   for ( i = 0; i < n-1; i++)
//   {
//     for ( j = 0; j < n-i-1; j++)
//     {
//       if (arr[j]>arr[j+1])
//       {
//         int temp = arr[j];
//         arr[j] = arr[j+1];
//         arr[j+1] = temp;   
//       }
//     }
//   }
//   for (i = 0; i < n; i++)
//   {
//     printf("%d, ", arr[i]);
//   }
//   return 0;
// }

// // Insertion sort
// int main(){
//   int n,i,j,k;
//   printf("Enter size of the array: ");
//   scanf("%d",&n);
//   int arr[n];
//   printf("Enter elements in array: ");
//   for ( i = 0; i < n; i++)
//     scanf("%d", &arr[i]);
//   for ( i = 0; i < n; i++)
//   {
//     k = arr[i];
//     j = i-1;
//     while (k<arr[j] && j>=0)
//     {
//       arr[j+1]=arr[j];
//       --j;
//     }
//     arr[j+1]= k;
//   }
//   for ( i = 0; i < n; i++)
//   {
//     printf("%d, ", arr[i]);
//   }
// }

// // Selection sort
// int main(){
  // int n, i,j,a,b;
  // printf("Enter size of the array: ");
  // scanf("%d", &n);
  // int arr[n];
  // printf("Enter elements in array: ");
  // for ( i = 0; i < n; i++)
  //   scanf("%d",&arr[i]);
//   for (i = 0; i < n-1; i++)
//   {
//     int check = i;
//     for ( j = i+1; j < n; j++)
//     {
//       if(arr[j]>arr[i])
//         check = j;
//       if (check != i)
//       {
//         int swap = arr[i];
//         arr[i] = arr[check];
//         arr[check] = arr[swap];
//       }
//     }  
//   }
//   for (i = 0; i < n; i++)
//     printf("%d\n", arr[i]);
//   return 0;
// }

// // Ex4
// int main(){
//   int n,i, sum;
//   printf("Enter the size: ");
//   scanf("%d", &n);
//   int arr[n];
//   printf("Enter the elemets: ");
//   for (i = 0; i < n; i++)
//     scanf("%d", &arr[i]);
//   for (i = 0; i < n; i++)
//     sum = sum+ arr[i];
//   printf("%d", sum);
// }

// // Ex5:
// int main(){
//   int m,n, i,j, sum =0;
//   printf("Please enter the number of rows: ");
//   scanf("%d", &m);
//   printf("Please enter the number of columns: ");
//   scanf("%d", &n);
//   int arr[m][n];
//   //Taking elements
//   for(i = 0; i<m; i++){
//     for(j=0; j<n; j++){
//       printf("Element at [%d][%d]: ",i,j);
//       scanf("%d", &arr[i][j]);
//       sum += arr[i][j];
//     }
//   } 
//   //Printing elements in matrix form
//   printf("The matrix form");
//   for(i = 0; i<m; i++){
//     printf("\n");
//     for(j=0; j<n; j++){
//       printf("%d\t", arr[i][j]);
//     }
//   }
//   printf("\n");
//   printf("The sum of all element is: %d",sum);
//   return 0;
// }
  
