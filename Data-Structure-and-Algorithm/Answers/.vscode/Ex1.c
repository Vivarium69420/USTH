#include <stdlib.h>
#include <stdio.h>

// Pseudo-code: 
// Problem: Check sphenic number, the number have exactly 3 distinct prime number that when multiply will equal such number
// 1. Set result as the counter for the number divisors
// 2. Set n as the user input
// 3. set i <- 2
// 4. if i <=n
// 5. Set count to check how many time does n being divided with the same divior
// 6. while(n%i==0)
// 7.   increment count 
// 8.   divide n by i
// 9. if count >= 2 
// 10.   Stop and return "not sphenic
// 11. if count == 1
// 12.   increment result
// 13    increment i
// 14. Go to Step 4
// 15. if res != 1 #meaning that it's the last diviors
// 16.   increment result
// 17. if res == 3   
// 18    Go to step 20
// 19. print "not sphenic"
// 20. print "sphenic number"
// 

int sphenic(int n){
  int result=0;
  for(int i = 2; i<=n;i++){ 
    int count = 0;
    while(n%i==0){
      ++count;
      n/=i;
    }
    if(count >= 2) return 0;
    if(count ==1){
      ++result;
    }
  }
  if(n!=1) 
    ++result;
  return result == 3;
}

int main(){
  int n;
  printf("Enter the number you want to check: ");
  scanf("%d", &n);
  if (sphenic(n)==1) printf(" Sphenic");
  else printf("Not Sphenic");
}
