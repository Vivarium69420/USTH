#include <stdio.h>
//Problem: Calculate the digits sum 
//Breakdown: 
//1st: Need to get individual digits from the natural number
//2nd: Sum up individual digits
//Pseudo-code:
//1. Set n as a user input
//2. Set c as the individual ditgit obtained when dividing the natural number
//3. Set result as the output result
//4. while (n != 0)
//5.    Set c equal to the remainder of n when divided to 10
//6.    Increment result by c
//7.    Divide n by 10
//8. end while 
//9. print result
//10. end
// Time Complexity: O(log(n))
// Explaination: The recursive variables are divided by a constant amount after each calls which is 10,
// the code never run fully to n and perform k iterations
// 10^k = n
// k = log10(n) -> O(log10(n)) = O(log(n))


int main(){
  int n;
  printf("Please enter a number: ");
  scanf("%d",&n);
  int c;
  int result;
  while(n!=0){
    c = n%10;
    result = result + c;
    n/=10;
  }
  printf("%d",result);
}
