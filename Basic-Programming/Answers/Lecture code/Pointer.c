#include <stdio.h>

void greeting(char* name){
  printf("Hello %s\n", name);
}

int* increase_element(int arr[], int size){
  for (int i = 0; i < size; i++)
  {
    arr[i] = arr[i]+1;
  }
  return arr;
}

int main(){
  int number = 10;
  int* ptr = &number;
  int result = *ptr +5;
  printf("THe value ptr is %d\n", *ptr);
  printf("Numeber wop: %d\n", result);
  char Student_name[]="Mai Hai Dang";
  greeting(Student_name);
  int arr[]={1,2,3,4,5,6,7,8,9,10};
  int* p = increase_element(arr, 10);
  printf("The value of p is %d\n", p);
  printf("The vlaue of arr is: %d\n", &p);
  for (int i = 0; i < 10; i++)
  {
    printf("Value %d\n", p[i]);
  }
}

int main(){
  int number[] = {1,2,3,4,5};
  int* p = number;
  int* p2 = &p[4];
  for (int i = 0; i < 5; i++)
  {
    printf("p pointing to %d\n", *p2);
    p2--;
  }
}

int main(){
  int A[]= {1,2,3,4};
  int* p = A[2];
  for (int i = 0; i < sizeof(A); i++)
  {
    printf("Value: %d\n", A[2]);
    p++;
  }
}

int main(){
  int n, i, *ptr, sum =0;
  printf("Enter number of element: ");
  scanf("%d", &n);
  ptr = (int*) malloc(n*sizeof(int));
  if(ptr == NULL){
    printf("NO FUCK YOU");
    exit(0);
  }
  printf("Enter elements: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", ptr + i);
    sum += *(ptr +i);
  }
  printf("Sum = %d", sum );
  free(ptr);
  return 0;  
}
