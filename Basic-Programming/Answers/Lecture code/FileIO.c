#include <stdio.h>
#include <stdlib.h>

int main(){
  char ch;
  FILE *fp=fopen("Hello.txt","r");
  if (fp == NULL)
  {
    printf("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }
  printf("The content:\n");
  while((ch=fgetc(fp)) !=EOF)
  printf("%c", ch);

  fclose(fp);
  return 0;
}