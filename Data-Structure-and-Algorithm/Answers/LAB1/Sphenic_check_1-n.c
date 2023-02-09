#include <stdlib.h>
#include <stdio.h>
#include <math.h>
// Problem: Find all sphenic number from 1 to n
// Breakdown:
// 1st: Check if the number is sphenic
// 2nd: Slowly reduce the n until it reach 30 which is the first sphenic number

// Pseudo-code:
// 1. Set result as the counter for the number divisors
// 2. Set n as the user input
// 3. Set temp == n  temporary value of n before changes
// 4. if n == 30 print out number 30 then stop the program
// 5. set i <- 1
// 6. if i <= temp
// 7. Set count to check how many time does input being divided with the same divior
// 8. while(temp%i==0)
// 9.    increment count 
// 10.   divide temp by i
// 11. if count >= 2 then
// 12.   n = n-1
// 13.   go to step 3
// 14. if count == 1
// 15.   increment result
// 16    increment i
// 17.   Go to Step 4
// 18. if res != 1 then #meaning that it's the last diviors
// 19.   increment result
// 20. if res == 3 and n!=30 then
// 21.    print value of n
// 22.    go to Step 4

// Complexity: O(n)

int reduce(int n){
  return --n;
}
int sphenic(int n){
  if (n==30){
    printf("%d",n);
    return 1;
  } 
  int result=0;
  int temp = n;
  for(int i = 2; i<=sqrt(temp);i++){ 
    int count = 0;
    while(temp%i==0){
      ++count;
      temp/=i;
    }
    if(count >= 2) return sphenic(reduce(n));
    if(count ==1){
      ++result;
    }
  }
  if(temp!=1) 
    ++result;

  if(result==3 && n!=30)
    printf("%d, ", n);
  
  return sphenic(reduce(n));
}

int main(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    sphenic(n);
}
