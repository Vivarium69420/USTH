#include <stdio.h>

int sum(int n, int result){
  if(n==0){
    printf("%d", result);
    return 0;
  }
  int c;
  c = n%10;
  result += c;
  return sum(n/=10,result);
}

int main(){
  int n;
  printf("Please enter a number: ");
  scanf("%d",&n);
  int result = 0;
  sum(n,result);
}
// Time Complexity: O(log(n))
// Explaination: The recursive variables are divided by a constant amount after each calls which is 10,
// the code never run fully to n and perform k iterations
// 10^k = n
// k = log10(n) -> O(log10(n)) = O(log(n))
