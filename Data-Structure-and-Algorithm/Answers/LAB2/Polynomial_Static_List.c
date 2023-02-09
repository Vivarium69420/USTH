#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// one list that store both degree and value
typedef struct List{ 
  int value[50];
  int degree[50];
} ADT;

//initialize the array with every values of the list = 0 and the degree run from 1 to n
void init(ADT *I){
  for(int i =0; i<=50;i++){
    I->value[i]=0;
    I->degree[i]=i;
  }
}

//check if value == 0
int check1(ADT *I, int index){
  int val=I->value[index]; //since deg and val is at the same index, just need to check if index has a value
  if(val ==0)
    return 0; // return 0 if it equal 0
  else
    return 1; // return 1 if it has value
}


// check the number of element entered
int length(ADT *I){
  int res =1;
  for(int i = 1; i<=50;i++){
    if(check1(I,i)==1){  
      res++;
    }
  }
  return res;
}

// add a value to the array
void add(ADT *I, int index, int val){ 
  if(index>50){
    printf("Invalid index!\n");  // if the index surpass the capacity, return invalid
    return;
  } 
  if(index<=50){ //otherwise the value at that index = to the user input value
    I->value[index] += val; //if already exist an value, just take a sum of the old val and input
  }
}

// remove an value by setting it equal to 0
void remove1(ADT *I, int index){
  I->value[index] = 0;
}
// calculate at x
void calculate(ADT *I, int x){
  int res = 0;
  for(int i = 0; i<=50;i++){
    if(check1(I,i)==1){ //check if at index i it has a value, then fetch the value and degree at such index
      int val =I->value[i];
      int de = I->degree[i];
      int pow1 = pow(x,de); //just power
      res = res + val*pow1;
    }
  }
  printf("Value of the function at x = %d is %d\n",x,res);
}
//Display the function
void funcDis(ADT *I){
  int size = length(I)-2; //number of elements omit the first and last index
  if(I->value[0]>0) //if the value at index 0 exist, print it first, otherwise skip
    printf("%d +",I->value[0]);
  if(I->value[1]>0){ //if the value at index 1 exist, print it first, otherwise skip
    printf(" %dx +",I->value[1]);
  }
  for(int i = 2; i<50;i++){
    if(check1(I,i)==1){ //start printing values and it correspoding degree
      int val = I->value[i];
      int de = I->degree[i];
      printf(" %dx^%d ",val, de); 
      if(size>0){ //just add a plus size of still have elemnents
        printf("+");
        size--;
      }
    }
  }
}
int main(){
  ADT I;
  ADT *a = &I;
  init(a);
  add(a,0,3); //adding 3 to the index 0
  add(a,89 ,89); //will return invalid value
  add(a,15,24);
  add(a,22,-52);
  add(a,15,4);
  add(a,13,4);
  remove1(a,15);
  add(a,43,12);
  add(a,24,2);
  add(a,3,41);
  length(a); //check the number input
  calculate(a,1); //calculate the function at x=1
  funcDis(a); // display input funtion
}