#include "stack.h"

void init_stack(Stack *s, int size) {
    s->top = -1;
    s->MAX = size;
    s->stack = (int *)malloc(size * sizeof(int));
}

int stack_is_empty(Stack *s) {
    if (s->top == -1) {
        return 1;
    }
    return 0;
}

int stack_is_full(Stack *s) {
    if (s->top == (s->MAX) - 1) {
        return 1;
    }
    return 0;
}

void stack_push(Stack *s, int n) {
    if (!stack_is_full(s)) {
        s->top++;
        s->stack[s->top] = n;
    }
}

int stack_peek(Stack *s) {
    if (stack_is_empty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return s->stack[s->top];
}

int stack_pop(Stack *s) {
    int out = stack_peek(s);
    s->top--;
    return out;
}

void stack_print(Stack *s) {
    printf("The current stack is: \n\n");

    for (int i = s->top; i >= 0; i--) {
        printf("| %i |\n", s->stack[i]);
        printf("+---+\n");
    }
}
