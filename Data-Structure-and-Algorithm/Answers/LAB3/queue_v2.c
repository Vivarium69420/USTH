#include <stdio.h>
#include <stdlib.h>

/*
 * Customer
 * id: the customer id
 * name: the customer name
 * prod_quan: number of products bought
 * prod_name: the name of the product
 *
 * */

typedef struct Customer {
  char *name;
  int prod_quan;
  char *prod_name;
  struct Customer *next;
} customer_t;

/*
 * Item
 * id: the product id
 * name: the product name
 * in_stock: number of product left in stock
 *
 * */

typedef struct Item {
  char *name;
  int in_stock;
} item_t;

/*
 * Queue
 * size: the size of the queue
 * back: the back of the queue
 *
 * */

typedef struct Queue {
  int size;
  int count;
  customer_t *back;
} queue_t;

queue_t *initQueue(int size) {
  queue_t *queue = malloc(sizeof(queue_t));
  queue->size = size;
  queue->count = 0;
  queue->back = NULL;
  return queue;
}

item_t *initItem(char *name, int in_stock) {
  item_t *item = malloc(sizeof(item_t));
  item->name = name;
  item->in_stock = in_stock;
  return item;
}

customer_t *initCustomer(char *name, int prod_quan, char *prod_name) {
  customer_t *customer = malloc(sizeof(customer_t));
  customer->name = name;
  customer->prod_quan = prod_quan;
  customer->prod_name = prod_name;
  customer->next = NULL;
  return customer;
}

void enqueue(queue_t *queue, customer_t *customer) {
  if (queue->count == queue->size) {
    printf("Queue is full\n");
    printf("Customer %s left\n", customer->name);
    printf("---------------------\n");
    return;
  } else if (queue->back == NULL) {
    queue->back = customer;
    queue->count++;
    printf("Customer %s joined\n", customer->name);
    printf("The queue size is %d\n", queue->count);
    printf("---------------------\n");
    return;
  } else {
    customer_t *temp = queue->back;
    customer->next = temp;
    queue->back = customer;
    queue->count++;
    printf("Customer %s joined\n", customer->name);
    printf("The queue size is %d\n", queue->count);
    printf("---------------------\n");
    return;
  }
}

void dequeue(queue_t *queue) {
  customer_t *current = queue->back;
  customer_t *prev = current;
  if (queue->count == 0) {
    printf("Queue is empty\n");
    return;
  }
  if (queue->count == 1) {
    printf("Customer %s left\n", current->name);
    printf("---------------------\n");
    free(current);
    queue->count--;
    return;
  }
  while (current->next != NULL) {
    prev = current;
    current = current->next;
  }
  printf("Customer %s left\n", current->name);
  prev->next = current->next;
  free(current);
  queue->count--;
  printf("The queue size is %d\n", queue->count);
  printf("---------------------\n");
}

void purchase(queue_t *queue, customer_t *customer, item_t *item) {
  if (customer->prod_quan > item->in_stock || item->in_stock == 0 ||
      item->in_stock - customer->prod_quan < 0) {
    printf("Customer %s cannot purchase %d %s\n", customer->name,
           customer->prod_quan, customer->prod_name);
    printf("Not enough %s in stock: %d\n", customer->prod_name, item->in_stock);
    dequeue(queue);
    return;
  } else {
    item->in_stock -= customer->prod_quan;
    printf("Customer %s purchased %d %s\n", customer->name, customer->prod_quan,
           customer->prod_name);
    printf("There are %d %s left in stock\n", item->in_stock,
           customer->prod_name);
    dequeue(queue);
    return;
  }
}

int main() {
  queue_t *queue = initQueue(3);
  item_t *cola = initItem("Cola", 10);
  item_t *chips = initItem("Chips", 2);
  item_t *soda = initItem("Soda", 7);
  customer_t *customer1 = initCustomer("John", 5, "Cola");
  customer_t *customer2 = initCustomer("Jane", 2, "Chips");
  customer_t *customer3 = initCustomer("Jim", 3, "Soda");
  customer_t *customer4 = initCustomer("Jill", 2, "Soda");
  customer_t *customer5 = initCustomer("Jack", 1, "Chips");
  enqueue(queue, customer1);
  enqueue(queue, customer2);
  enqueue(queue, customer3);
  purchase(queue, customer1, cola);
  purchase(queue, customer2, chips);
  purchase(queue, customer3, soda);
  enqueue(queue, customer4);
  purchase(queue, customer4, soda);
  enqueue(queue, customer5);
  purchase(queue, customer5, chips);
  return 0;
}
