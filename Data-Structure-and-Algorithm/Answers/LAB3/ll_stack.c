/*
 * Implement the undo/redo mechanism using two stacks
 * Stack using Linked List
 *
 * */

/*
 * A simple node structure
 * string: contains the string
 * next: pointer to the next node
 * */
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  char *string;
  struct Node *next;
} node_t;

/*
 * A stack structure
 * size: the size of the stack
 * top: pointer to the top node
 * */
typedef struct Stack {
  int size;
  int count;
  node_t *top;
} stack_t;

stack_t *initStack(int size) {
  stack_t *stack = malloc(sizeof(stack_t));
  stack->size = size;
  stack->count = 0;
  stack->top = NULL;
  return stack;
};

node_t *initNode(char *string) {
  node_t *node = malloc(sizeof(node_t));
  node->string = string;
  node->next = NULL;
  return node;
};

void push(node_t *node, stack_t *stack) {
  if (stack->top == NULL) {
    stack->top = node;
  } else {
    node->next = stack->top;
    stack->top = node;
  }
  stack->count++;
};

node_t *pop(stack_t *stack) {
  if (stack->top == NULL) {
    printf("Stack is empty\n");
    exit(1);
  }
  if (stack->count == 1) {
    return stack->top;
  }
  stack->top = stack->top->next;
  stack->count--;
  return stack->top;
};

node_t *top(stack_t *stack) { return stack->top; };

void destroyStack(stack_t *stack) {
  if (stack->top == NULL) {
    printf("Stack is empty\n");
    return;
  }
  node_t *node = stack->top;
  while (node != NULL) {
    node_t *next = node->next;
    free(node);
    node = next;
  }
  free(stack);
}
void displayStack(stack_t stack) {
  node_t *node = stack.top;
  while (node != NULL) {
    printf("%s\n", node->string);
    node = node->next;
  }
};

int main() {
  stack_t *undo_stack = initStack(5);
  stack_t *redo_stack = initStack(5);

  node_t *node = initNode("Hello");
  push(node, undo_stack);

  node_t *pop_node = pop(undo_stack);
  printf("Popped node: %s\n", pop_node->string);
  push(pop_node, redo_stack);

  node_t *top_node = top(redo_stack);
  printf("Redo node: %s\n", top_node->string);

  return 0;
};
