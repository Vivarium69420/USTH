#include <stdio.h>
#include <math.h>

void sphenic(int n, int div, int *count, int *no){
  if(n<=1) return;
  if (n%div == 0){
    *no +=1;
    if(*no>=2) return;
    if(n>1) *count +=1;
    sphenic(n/div,div,count,no);
  }
  else{
    *no = 0;
    sphenic(n,div+1,count, no);
  }
}

int main(){
  int n=30;
  int p = 0;
  int no = 0;
  sphenic(n,2,&p,&no);
  if(p==3) printf("Sphenic");
  else printf("Not sphenic");
}