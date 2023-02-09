#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node{
  int num_pass;
  char name[20];
  struct _Node *next;
} Node;

typedef struct _List {
  int size;
  Node *head;
} List;

void initTrain(List *I){ 
  I->size = 0; 
  I->head = NULL;
}

Node *newNode(int number, char name[]){ //making new nodes, ba-by 
  Node *res = malloc(sizeof(Node)); //dynamically allocate the address of new nod
  res->num_pass = number; 
  res->next = NULL;
  strcpy(res->name,name); 
  return res; 
}

void add(List *I, int number, char name[]){
  Node *new = newNode(number, name);
  Node *p = I->head;
  if(p == NULL){ //if the head is null, newnode will be the head
    p = new;
    I->head = p;
    I->size++; //increase the size of list as we increse number of node
    return;
  }
  while(p->next!= NULL){ //transversing through the list to reach the ass
    p = p->next;
  }
  p->next = new; //p->next here is now the ass (that point to null) -> add new node to the ass
  I->size++;
}

void removeCar(List *I){
  Node *prev, *curr;
  prev = I->head;
  curr = I->head;
  while(curr!= NULL){ //check until you reach the ass
    if(curr->num_pass == 0){ //check if the train has no pass
      if(curr == I->head){ //check if it's the head
        printf("\n%d - %s removed", curr->num_pass, curr->name);
        I->head = curr->next; //if it's the first node then make the second node the head node
        free(curr);
        //reinit the curr and prev pointers
        prev = I->head;
        curr = I->head;
        I->size--;
      }
      else{ //if not the head node
        printf("\n%d - %s removed", curr->num_pass, curr->name);
        prev->next = curr->next; //set prev to the node in front of soon be deleted node
        free(curr); //delete node at the current position
        curr = prev->next; // set current as the node after deleted node
        I->size--; //reduce train size
      }
    }
    else{ //reinit the curr and prev, so it move down the list 
      prev = curr;
      curr = curr ->next;
    }
  }
}

void displayInfo(List *I){
  removeCar(I);
  Node *p = I->head;
  printf("\nTrain info: ");
  if(p==NULL){
    printf("\n Empty");
    return;
  }
  while(p->next!= NULL){
    printf("\n%d - %s", p->num_pass, p->name);
    p = p->next;
  }
  printf("\n%d - %s", p->num_pass, p->name); //print the last car
}

void displayLength(List *I){
  removeCar(I);
  Node *p = I->head;
  printf("\nLength of the train: %d", I->size);
}

int main(){
  List I;
  List *a=&I;
  initTrain(a);
  add(a, 0, "B1");
  add(a, 0, "B2");
  add(a, 2, "B3");
  add(a, 3, "B4");
  add(a, 4, "B5");
  displayInfo(a);
  displayLength(a);
}