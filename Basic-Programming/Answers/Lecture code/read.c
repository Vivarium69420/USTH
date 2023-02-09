#include <stdio.h>
#include <stdlib.h>
int main(){
  FILE* p = fopen("DM3.txt","r");
  char c;
  while ((c=fgetc(p)) !=EOF);
  {
    printf("%c", c);
    printf("\b");
  }
  return 0;
}