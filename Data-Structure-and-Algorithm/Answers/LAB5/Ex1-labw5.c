#include <stdlib.h>
#include <stdio.h>

//Pseudo-code:
// 1. Set arr[] as an array that hold sequence of number
// 2. Set n as the size of the array
// 3. check <- 1 
// 4. start <- 0
// 5. end <- n
// 6. for i<-(start+1) to end do
// 7.     key <- arr[i]
// 8.     j = i-1
// 9.     if arr[j] < key
// 10.        break
// 11.    end if
// 12.    while arr[j] > key
// 13.        swap a[j+1] and a[j]
// 14.    end while
// 15.    i = i+1
// 16. end for
// 17. check <-0
// 18. for i<-(end-1) to start do
// 19.     if arr[i] > arr[i+1]
// 20.        swap a[i+1] and a[i]
// 21.        check = 1
// 22.     end if
// 23.     i=i-1
// 24. end for
// 25. if check == 1
// 26.     go to 6
// 27. end if
// 28. if check == 0
// 29.     stop
// 30. end if

// Complextiy:
// Best case: The list already sorted so the loops only run n times -> O(n)
// Average case: If the value only a few index off the correct position,
//               and for example it take n/2 time to get sorted,
//               it will take (n/2)(n/2) times to get the list sorted -> O(n^2)
// Worst case: The largest value is at the beginning and smallest value at the bottom,
//               the loop have to run n*n times to get the list sorted -> O(n^2)
void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort(int a[], int n){
  int key;
  int check = 1;
  int start =0;
  int end = n;
  here:
  for(int i=start+1;i<=end;i++){
    key = a[i];
    int j = i-1;
    if(a[j]<key)
      break;
    while(a[j]>key){
      swap(&a[j+1], &a[j]); 
    }
  }
  check =0;
  for(int i = end-1;i>=start;--i){
    if(a[i]>a[i+1]){
      swap(&a[i+1], &a[i]);
      check = 1;
    }
  }
  start++;
  if(check ==1)
    goto here;
  
  if(check ==0)
    return;
  
}

void printArray(int arr[], int size){
  int i;
  for(i=0;i<size;i++)
    printf("%d ", arr[i]);
  printf("\n ");
}

int main()
{
  int i, n=7; //n is size of array
  int A[] ={1,55,44,22,66,88,33,11};
  sort(A, n);
  printf("Sorted array: \n");
  printArray(A, n);
  return 0;
}