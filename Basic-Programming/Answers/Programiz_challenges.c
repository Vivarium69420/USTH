#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Ex5: Find ASCII Value of a Charater
int main(){
  char key = 'A';
  printf("%d", key);
}

// Ex: Vowel or Consonant
int main(){
  char he;
  char vowel[5]={'a', 'e', 'i', 'o', 'u'};
  printf("Enter a lowercase character: ");
  scanf("%c", &he);
  for (int i = 0; i < 5; i++)
  {
    if(he==vowel[i])
      printf("You entered a vowel");  
    else{
      printf("You entered a consonant");
      break;
    }
  }
  return 0;
}

// Ex: Check Palinedrome Number
int main(){
  int n, rem = 0, rev, ori;
  printf("Please enter a number: ");
  scanf("%d", &n);
  ori = n;
  while(n!=0){
    rem = n % 10;
    rev = rev*10 + rem;
    n/=10;
  }
  if(ori==rev)
    printf("%d is a palindrome", ori);
  else
    printf("%d is not a palindrome", ori);
}

// Ex: Negative or Positive
int main(){
  int n, b=0;
  scanf("%d", &n);
  return (n<b) ? printf("Negative") : printf("Positive");
}

// Ex: LCM
int main(){
  int a, b, max;
  printf("Enter 2 number: ");
  scanf("%d%d", &a, &b);
  max = (a>b)? a: b;
  while(1){
    if(max%a ==0 && max%b==0){
      printf("LCM = %d", max);
      break;
    }
    max++;
  }
}

// Ex: Prime Number between an Interval
int main(){
  int lower, upper, i,j;
  printf("Enter the lower and upper bound of the interval: ");
  scanf("%d%d", &lower, &upper);
  for (i = lower; i <= upper; i++)
  {
    int k=0;
    for (j = 1; j<=i; j++)
    {
      if(i%j==0) 
      k++;
    }
    if(k==2)
      printf("%d, ",i);
  }
}

// Ex: Count the number of digits
int main(){
  int n, count;
  printf("Please enter a number: ");
  scanf("%d", &n);
  while(n!=0){
    n /=10;
    count++;
  }
  printf("Number size: %d", count);
}

// Ex: Find GCD using recursion
int gcd(int a, int b){
  if(b!=0)
    return gcd(b, a%b);
  else
    return a;
}
int main(){
  int a,b, result;
  printf("Please enter 2 number: ");
  scanf("%d%d",&a,&b);
  result = gcd(a,b);
  printf("%d",result);
}

// // Ex: Add 2 matrices
int main(){
  int n,i,j;
  printf("Set matrix size: ");
  scanf("%d", &n);
  int matrix1[n][n];
  int matrix2[n][n];
  int sum[n][n];
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      printf("Please enter the element [%d][%d]",i,j);
      scanf("%d",&matrix1[i][j]);
    }
  }
  printf("\nYour first matrix:\n ");
  for (i = 1; i <= n; i++)
  {
    printf("\n");
    for (j = 1; j <= n; j++)
    {
      printf("[%d]\t",matrix1[i][j]);
    } 
  }
  printf("\nSecond matrix:\n");
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      printf("Please enter the element [%d][%d]",i,j);
      scanf("%d",&matrix2[i][j]);
    }
  }
  printf("\n");
  printf("Your second matrix: ");
  for (i = 1; i <= n; i++)
  {
    printf("\n");
    for (j = 1; j <= n; j++)
    {
      printf("[%d]\t",matrix2[i][j]);
    } 
  }
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      sum[i][j] = matrix1[i][j] + matrix2[i][j];
    }  
  } 
  printf("\n");
  printf("Your sumation matrix: ");
  for (i = 1; i <= n; i++)
  {
    printf("\n");
    for (j = 1; j <= n; j++)
    {
      printf("[%d]\t",sum[i][j]);
    } 
  }
}

// Ex: Multiply 2 matrices by passing matrix to a function
int main(){
  int a,b, n,m,i,j;
  printf("Please enter the size of matrix 1: \n");
  scanf("%d%d",&a,&b);
  printf("Please enter the size of matrix 2: \n");
  scanf("%d%d",&n,&m);
  while(b!=n){
    printf("Error! Column of the first matrix not equal to the row of second matrix");
    printf("Please enter the size of matrix 1: \n");
    scanf("%d%d",&a,&b);
    printf("Please enter the size of matrix 2: \n");
    scanf("%d%d",&n,&m);
  }
  int ma1[a][b];
  int ma2[n][m];
  
  printf("First matrix: \n");
  for (i = 1; i <= a; i++)
  {
    for (j = 1; j <= b; j++)
    {
      printf("Please enter elements[%d][%d]: ",i,j);
      scanf("%d", &ma1[i][j]);
    }
  }
  printf("Second matrix: \n");
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= m; j++)
    {
      printf("Please enter elements[%d][%d]: ",i,j);
      scanf("%d",&ma2[i][j]);
    }
  }
  int mult[a][m];
  for(i=1; i<=a; i++){
    for(j=1; j<=m;j++){
      for (int k = 1; k <= b; k++){
        mult[i][j]+= ma1[i][k] * ma2[k][j];
      }
    }
  }
  for(i=1; i<=a; i++){
    printf("\n");
    for(j=1; j<=m;j++){
      printf("%d\t",mult[i][j]);
    }
  }
  return 0;
}