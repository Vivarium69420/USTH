#include<iostream>
#define max 100
using namespace std;
typedef struct _Stack{
  char data[max];
  int top;
}stack;

int charCheck(char input_char)
{
  // CHECKING FOR ALPHABET
  if ((input_char >= 65 && input_char <= 90) || (input_char >= 97 && input_char <= 122))
    return 1;
  // CHECKING FOR DIGITS
  else if (input_char >= 48 && input_char <= 57)
    return 2;
  // OTHERWISE SPECIAL CHARACTER
  else
    return 3;
}
 
void initStack(stack* I){
  I->top = -1;
}

int isEmpty(stack *I){
  if (I->top < 0)
    return 1;
  return 0;
}

int size(stack *I) {
  return (I->top+1);
}


void push(stack *I, char str){
  if (I->top > 100)
    cout << "stack is full!\n";
  else{
    I->top++;
    I->data[I->top] = str;
    return;
  }
}

void pop(stack *s1, stack *s2, int num){
  if (isEmpty(s1) == 1 && isEmpty(s2) == 1){
    cout << "\nstack is empty";
    return;
  }
  else {
    for (int i = 0; i < num; i++){
      push(s2, s1->data[s1->top]);
      s1->top--;
    }
    return;
  }
}

int length(stack *I) {
  return (I->top + 1);
}

void display(stack *I){
  if (isEmpty(I) == 1)
    cout << "stack is empty\n";
  if (I->top >100)
    cout << "stack is full\n";
  else {
    for(int i = 0; i < length(I) ; i++) {
      cout << I->data[i];
    } 
  }
  cout << "\n";
}

int main(){
  stack undo, redo;
  stack *s1 = &undo;
  stack *s2 = &redo;
  initStack(s1);
  initStack(s2);
  int n1,n2,n3;
  cout << "Number character(s) will you add: ";
  cin >> n1;
  for(int i = 0; i<n1;i++){
    char str;
    cout << "Enter character(s): ";
    cin >> str;
    while(charCheck(str)!=1){
      cout << "Invalid input, try again: ";
      cin >> str;
    }
    push(s1,str);
  }
  cout << "\nThe original text: ";
  display(s1);
  cout << "\nDo ya wanna redo dat?\n Type 1 if Yes, Type 2 if No\n";
  do{
    cin >> n2;
    if(n2<1 || n2>2){ //check if input choice is invalid
    cout <<"Invalid input. Try again: ";
    }
  } while(n2<1 || n2 >2);
  if(n2 ==2){
    cout << "\nBye!!!";
    return 0;
  }
  if(n2 ==1 ){
    cout << "\nOk, by how many character you want to redo?\n REQUIREMENT: 0<Input<number_character_entered \nEnter:  ";
    do{
      cin >> n3;
      if((n3>n1+1) || n3<0){ //check if input choice is invalid
      cout <<"Invalid input. Try again: ";
      }
    } while(n3>(n1+1) || n3<0);
    pop(s1,s2,n3);
    cout <<"\nThe undo stack: ";
    display(s1);
    cout <<"\nThe redo stack: ";
    display(s2);
  }

}