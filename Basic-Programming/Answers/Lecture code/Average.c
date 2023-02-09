#include "Average.h"
float Average(int numbers[], int size){
  float sum = 0;
  float avg = 0;
  for(int i = 0; i < size; i ++){
    sum += numbers[i];
  }
  if(size>0){
    avg = (float)sum/size;
  }
  else{
    avg = -1;
  } 
  return avg;
}