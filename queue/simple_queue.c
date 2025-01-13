#include "queue.h"

int main() {
    Queue q;
    init_queue(&q, 5);
    int cont = 1;

    while (cont) {
        printf("\n");
        int choice;
        printf("1. Enqueue\n2. Dequeu\n3. Print front \n4. Print all the "
               "elements\n5. Quit\n");
        scanf("%i", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to be enqueued\n");
                int val;
                scanf("%i", &val);
                enqueue(&q, val);
                queue_print(&q);

                break;
            case 2:
                val = dequeue(&q);
                printf("Dequeued element %i successfully\n", val);
                queue_print(&q);
                break;

            case 3:
                printf("Front element is %i\n", queue_peek(&q));
                break;
            case 4:
                queue_print(&q);
                break;
            case 5:
                cont = 0;
                break;
            default:
                break;
        }
    }
}