#include <stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct _Node{
  int data;
  struct _Node *next;
  struct _Node *prev;
} node;

typedef struct _List{
  int size;
  node *head;
  node *tail;
} list;

void initList(list *I){
  I->size = 0;
  I->head = NULL;
  I->tail = NULL;
}

node *newNode(int number){
  node *res = malloc(sizeof(node)); //allocate
  res->data = number; //pass value
  res->prev = NULL;
  res->next = NULL;
  return res; //return node address
}

void add(list *I,int val){
  node *new = newNode(val);
  if (I->tail ==NULL){
    new->prev = NULL;
    I->head = I->tail= new;
  }
  else{
    new->prev = I->tail;
    I->tail->next = new;
  }
  I->tail = new;
  I->size++;
}
int checkSort = 0;//global sort checker
int checkSorted =0;

void sortForward(list *I){

  node *p = I->head;
  int c=0;
  for(int i = 0; i<checkSort;i++){ //everytime a value is sorted, the pointer will move up, so as to not check the same value twice
    p=p->next;
    c++;
  }

  node *q = p->next;

  int tmp; 
  if(p == NULL){
    printf("The list is empty.");
    return;
  }
  while(c<(I->size-1)){
    if(p->data > q->data){
      tmp = p->data;
      p->data = q->data;
      q->data = tmp;
    }
    q=q->next;
    p=p->next;
    c++;
    checkSorted = 1;
  }    
  checkSort++;
}

void sortBackward(list *I){
  node *p = I->tail;
  int c=0;
  for(int i = 0; i<checkSort;i++){
    p=p->prev;
    c++;
  }
  node *q = p->prev;
  int tmp;
  
  if(p == NULL){
    printf("The list is empty.");
    return;
  }
  while(c<(I->size-1)){
    if(p->data < q->data){
      tmp = p->data;
      p->data = q->data;
      q->data = tmp;
    }
    p=p->prev;
    q=q->prev;
    c++;
    checkSorted =1;
  }
}    

void sort(list *I){
  while(checkSort<sqrt(I->size)){
    sortForward(I);
    sortBackward(I);
  }
}

void display(list *I){
  if(I->head==NULL){
    printf("List is empty");
    return;
  }
  else{
    node *p = I->head;
    int c=0;
    while(c<I->size-1){
      printf("%d, ", p->data);
      p = p->next;
      c++;
    }
    printf("%d",p->data);
  }
}



int main(){
  list I;
  list *a = &I;
  initList(a);
  add(a,99);
  add(a,55);
  add(a,44);
  add(a,22);
  add(a,66);
  add(a,88);
  add(a,33);
  add(a,11);
  add(a,100);
  add(a,51242);
  add(a,1231);
  add(a,1);
  add(a,12323);
  add(a,2);
  printf("\n");
  sort(a);
  display(a);
  
}