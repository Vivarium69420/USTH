#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Ex1
int main(){
  double celcius;
  printf("Please enter your desire temperature: ");
  scanf("%lf", &celcius);
  printf("Here is your temperature in Fahrenheigh:%f ", (celcius*1.8 +32));
  return 0; 
}

// Ex2:
int main(){
  int number[3];
  int size =3; 
  printf("Please enter a number: ");
  for(int i =0; i<size; i++){
    scanf("%d", &number[i]);
  }
  int min = number[0];
  int max = number[0];
  for(int i =0; i<size; i++){
    if(number[i]<min){
      min = number[i];
    }
    if (number[i]>max)
    {
      max = number[i];
    }
    
  }
  printf("The minimun number %d and the maximum number %d", min, max);
}

// Ex3:
  int main(){
  int x;
  int y;
  printf("Pwease enwer a nuwuber OwO: ");
  scanf("%d", &x);
  printf("Pwease enwer a nuwuber OwO: ");
  scanf("%d", &y);
  int x_1 = (x+y)-x;
  int y_1 = (x+y)-y;
  printf("Before x=%d, y=%d and after x=%d, y=%d",x,y, x_1, y_1);
}

// Ex4
int main(){
  int x;
  printf("Please enter a year: ");
  scanf("%d", &x);
  if(x%4 ==0 && x%400==0){
    printf("Year of %d is a leap year", x);
  } else if (x%100==0)
  {
    printf("Year of %d isn't a leap year", x);
  } else {
    printf("Year of %d isn't a leap year", x);
  }
}

// Ex 5: 
int main(){
  double a;
  double b;
  double c;
  double d;
  double e;
  double f;
  double x;
  double y;
  printf("Please enter the value for a: ");
  scanf("%lf", &a);
  printf("Please enter the value for b: ");
  scanf("%lf", &b);
  printf("Please enter the value for c: ");
  scanf("%lf", &c);
  printf("Please enter the value for d: ");
  scanf("%lf", &d);
  printf("Please enter the value for e: ");
  scanf("%lf", &e);
  printf("Please enter the value for f: ");
  scanf("%lf", &f);
  printf("%fx+%fy=%f\n", a, b, c);
  printf("%fx+%fy=%f\n", d, e, f);
  y=(a*f-d*c)/(a*e-d*b);
  x=(c-b*y)/a;
  printf("The value for x is %f, and the value for y is %f", x,y);
  return 1.00;
}
  
// Ex6:
int main(){
  int month;
  char day_Month[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  Here:
  printf("Enter a month: ");
  scanf("%d", &month);
  while (month <=12)
  {
    goto There;
  }
  if(month>12)
  {
    printf("Invalid month, Please enter again.\n");
    goto Here;
  }
  There: 
  switch (month)
  {
  case 1:
    printf("Day in month %d", day_Month[0]);
    break;
  case 2:
    printf("Day in month %d", day_Month[1]);
    break;
  case 3:
    printf("Day in month %d", day_Month[2]);
    break;
  case 4:
    printf("Day in month %d", day_Month[3]);
    break;
  case 5:
    printf("Day in month %d", day_Month[4]);
    break;
  case 6:
    printf("Day in month %d", day_Month[5]);
    break;
  case 7:
    printf("Day in month %d", day_Month[6]);
    break;
  case 8:
    printf("Day in month %d", day_Month[7]);
    break;
  case 9:
    printf("Day in month %d", day_Month[8]);
    break;
  case 10:
    printf("Day in month %d", day_Month[9]);
    break;
  case 11:
    printf("Day in month %d", day_Month[10]);
    break;
  case 12:
    printf("Day in month %d", day_Month[11]);
    break;
  default: 
    break;
  }
}