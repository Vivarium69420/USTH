#include <stdio.h>
#include "Average.h"
int main(){
  int numbers[10];
  int count = 10;
  long sum = 0;
  float average = 0;
  printf("\nEnter 10 number: \n");
  for (int i = 0; i < count; i++)
  {
    printf("%2d>", i+1);
    scanf("%d", &numbers[i]);
  }
  average = Average(numbers, count);
  printf("\nAverage of these numbers entered is: %f\n", average);
  return 0;
}