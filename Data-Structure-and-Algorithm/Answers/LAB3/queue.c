#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
  char name_human[100]; // name of buyer
  char name_items[100]; // name of items
  int quantity;
  int items; // items ID, this make the process of choosing items much easier,
             // no need to mess around with strings as input choice
  struct _Node *next;
} node;

typedef struct _Queue {
  node *front, *back;
  int size;
  int capacity;
} queue;

void initQueue(queue *I, int val) {
  I->size = 0;
  I->front = I->back = NULL;
  I->capacity = val;
}

void enqueue(queue *I, char name_human[], int items, int quantity) {
  node *p = (node *)malloc(sizeof(node));
  strcpy(p->name_human, name_human);
  p->items = items; // item IDS
  p->quantity = quantity;
  p->next = NULL;
  if (I->front == NULL) // put the first person in the front of the queue
    I->front = I->back = p;
  if (I->size >= I->capacity) { // check if queue is full
    printf("\nSorry %s the queue is full\n", p->name_human);
    return;
  } else {
    p->next = I->back;
    I->back = p;
  }
  I->size++;
}

void dequeue(queue *I) {
  if (I->front == NULL)
    return;
  else {
    if (I->size == 1) { // if the queue only has 1 person
      printf("\n%s has dequeued\n", I->front);
      I->front = I->back = NULL;
      I->size--;
    } else {
      node *p = I->back; // starting from the back
      while (p->next != I->front) {
        p = p->next; // slowly push the line up
      }
      // after "while"
      printf("%s has dequeued\n", I->front);
      I->front = p;          // second person is now first
      I->front->next = NULL; // make sure the front->next is null
      I->size--;
    }
  }
}

node *initItems(int val, char name[]) { // initialize all items with it
                                        // corresponding name and capacity
  node *a = (node *)malloc(sizeof(node));
  strcpy(a->name_items, name);
  a->quantity = val;
  return a;
}

void display(node *a, node *b,
             node *c) { // display the name and quantity of the 3 items
  printf("\nItem name: %s. Item ID: 1. Item quantity: %d", a->name_items,
         a->quantity);
  printf("\nItem name: %s. Item ID: 2. Item quantity: %d", b->name_items,
         b->quantity);
  printf("\nItem name: %s. Item ID: 3. Item quantity: %d\n", c->name_items,
         c->quantity);
}

void purchase(queue *I, node *a, node *b,
              node *c) { // checking for purchase requirements
  node *p = I->front;
  int count = 0;
  if (p == NULL) {
    printf("\nThe Queue is empty");
    return;
  }
  while (count <= (I->capacity)) {
    node *p = I->front;
    if (p->items < 0 || p->items > 3)
      printf("\nSorry!!! We do not have such items %s", p->name_human);
    if (p->items == 1 && a->quantity > 0) {
      if (p->quantity >
          a->quantity) { // if the person want more than the stock can offer
        printf("\n%s wanted %d product(s) for %s, but the stock is only %d\n",
               p->name_human, p->quantity, a->name_items, a->quantity);
      } else { // if the stock can statisfy the need, just let 'em buy
        printf("\n%s purchase success: %d %s", p->name_human, p->quantity,
               a->name_items);
        a->quantity -= p->quantity;
        if (a->quantity == 0) { // check if there is any leftover stock
          printf("\nNo stock for %s left\n", a->name_items);
        } else
          printf("\nStock left for %s : %d\n", a->name_items, a->quantity);
      }
    }
    if (p->items == 2 && b->quantity > 0) {
      if (p->quantity > b->quantity) {
        printf("\n%s wanted %d product(s) for %s, but the stock is only %d\n",
               p->name_human, p->quantity, b->name_items, b->quantity);
      } else {
        printf("\n%s purchase success: %d %s", p->name_human, p->quantity,
               b->name_items);
        b->quantity -= p->quantity;
        if (b->quantity == 0) {
          printf("\nNo stock for %s left\n", b->name_items);
        } else
          printf("\nStock left for %s: %d\n", b->name_items, b->quantity);
      }
    }
    if (p->items == 3 && c->quantity > 0) {
      if (p->quantity > c->quantity) {
        printf("\n%s wanted %d product(s) for %s, but the stock is only %d\n",
               p->name_human, p->quantity, c->name_items, c->quantity);
      } else {
        printf("\n%s purchase success: %d %s", p->name_human, p->quantity,
               c->name_items);
        c->quantity -= p->quantity;
        if (c->quantity == 0) {
          printf("\nNo stock for %s left\n", c->name_items);
        } else
          printf("\nStock left for %s: %d\n", c->name_items, c->quantity);
      }
    }

    count++;
    dequeue(I);
  }
}

int main() {
  queue I;
  queue *a = &I;
  // create items IDs
  node *ID1 = initItems(5, "Water Bottle");
  node *ID2 = initItems(5, "Soft Drink Can");
  node *ID3 = initItems(5, "Alchohol Bottle");
  initQueue(a, 4); // initialize the size of queue
  display(ID1, ID2, ID3);
  enqueue(a, "Scarem", 1, 5); // 1st person
  enqueue(a, "Carls", 2, 12); // 2nd person
  enqueue(a, "Jenes", 3, 2);  // 3rd person
  enqueue(a, "Barel", 3, 1);  // etc
  enqueue(a, "James", 3, 2);
  purchase(a, ID1, ID2, ID3);
}
