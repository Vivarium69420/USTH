#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int checkPrime(int n){
  for(int i =2; i<sqrt(n);i++){
    if(n%i==0){
      return 0;
    }
    return 1;
  }
}

int sphenic(int n){
  if(checkPrime(n)){
    printf("Prime, so not sphenic");
  }
  if (n==30){
    printf("Sphenic");
    return 1;
  } 
  int result=0;
  int temp = n;
  for(int i = 2; i<=(temp)/2;i++){ 
    int count = 0;
    while(temp%i==0){
      ++count;
      temp/=i;
    }
    if(count >= 2){
      printf("Not Sphenic");
    }
    if(count ==1){
      ++result;
    }
  }
  if(temp!=1) 
    ++result;

  if(result==3)
    printf("Sphenic");
}
int main(){
  int n = 66;
  sphenic(n);
  return 0;
}