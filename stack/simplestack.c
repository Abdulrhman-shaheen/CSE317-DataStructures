#include "stack.h"
int main() {
    int cont = 1;
    Stack s;
    init_stack(&s, 10);
    while (cont) {
        printf("\n");
        int choice;
        printf("1. Push\n2. Pop\n3. Print the top element\n4. Print all the "
               "elements\n5. Quit\n");
        scanf("%i", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to be pushed\n");
                int val;
                scanf("%i", &val);
                stack_push(&s, val);
                stack_print(&s);
                break;
            case 2:
                val = stack_pop(&s);
                printf("Popped element %i successfully\n", val);
                stack_print(&s);
                break;

            case 3:
                printf("Top element is %i\n", stack_peek(&s));
                break;
            case 4:
                stack_print(&s);
                break;
            case 5:
                cont = 0;
                break;
            default:
                break;
        }
    }
}
