#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int MAX;
  int *stack;
  int top;
} Stack;

void init_stack(Stack *s, int size);
int stack_is_empty(Stack *s);
int stack_is_full(Stack *s);
void stack_push(Stack *s, int n);
int stack_peek(Stack *s);
int stack_pop(Stack *s);
void stack_print(Stack *s);

