#include "queue.h"

/*********************************************
 * Array-Based Queue Implementation
 *********************************************/
void init_queue(Queue* Q, int sz) {
    Q->front = -1;
    Q->rear = -1;
    Q->MAX = sz;
    Q->queue = (int*)malloc(sizeof(int) * sz);
}

int queue_is_empty(Queue* q) {
    return q->front == -1;
}

int queue_is_full(Queue* q) {
    return (q->rear + 1) % (q->MAX) == q->front;
}

void enqueue(Queue* q, int a) {
    if (queue_is_full(q)) {
        printf("Attempt to push failed! Queue is full\n");
        exit(1);
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->MAX;
    q->queue[q->rear] = a;
}

int queue_peek(Queue* q) {
    if (queue_is_empty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return q->queue[q->front];
}

int dequeue(Queue* q) {
    int f = queue_peek(q);
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
        return f;
    }
    q->front = (q->front + 1) % q->MAX;
    return f;
}

void queue_print(Queue* q) {
    if (queue_is_empty(q)) {
        printf("Empty Queue!\n");
        return;
    }
    int n = q->rear - q->front + 1;
    if (q->front > q->rear) {
        n += q->MAX;
    }

    for (int i = 0; i < n; i++) {
        printf("--- ");
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf(" %i |", q->queue[(q->front + i) % q->MAX]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("--- ");
    }
    printf("\n");
}

/*********************************************
 * Linked List-Based Queue Implementation
 *********************************************/
void init_llqueue(llQueue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int llqueue_is_empty(llQueue* q) {
    return (q->front == NULL && q->rear == NULL);
}

void llenqueue(llQueue* q, int a) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = a;
    temp->link = NULL;
    if (llqueue_is_empty(q)) {
        q->front = temp;
        q->rear = temp;
        return;
    }
    q->rear->link = temp;
    q->rear = temp;
}

int llqueue_peek(llQueue* q) {
    if (llqueue_is_empty(q)) {
        printf("Queue is Empty!\n");
        exit(1);
    }
    return q->front->val;
}

int lldequeue(llQueue* q) {
    if (llqueue_is_empty(q)) {
        printf("Queue is Empty!\n");
        exit(1);
    }

    int temp = q->front->val;
    Node* temp_n = q->front;

    q->front = q->front->link;
    if (q->front == NULL) {
        q->rear = NULL;  // Empty Stack
    }

    free(temp_n);
    return temp;
}

void llqueue_print(llQueue* q) {
    if (llqueue_is_empty(q)) {
        printf("Queue is Empty!\n");
        return;
    }
    Node* temp = q->front;

    while (temp != NULL) {
        printf("| %d |", temp->val);
        temp = temp->link;
    }
    printf("\n");
}

/*********************************************
 * Priority Queue Implementation
 *********************************************/
void init_prioqueue(Prio_Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int prioqueue_is_empty(Prio_Queue* q) {
    return (q->front == NULL && q->rear == NULL);
}

void prioenqueue(Prio_Queue* q, int a, int p) {
    Prio_Node* new_node = (Prio_Node*)malloc(sizeof(Prio_Node));

    new_node->val = a;
    new_node->p = p;
    new_node->link = NULL;

    if (prioqueue_is_empty(q)) {
        q->front = new_node;
        return;
    }

    Prio_Node* temp = q->front;

    if (p > temp->p) {
        q->front = new_node;
        new_node->link = temp;
        return;
    }
    while (temp->link != NULL && temp->link->p >= p) {
        temp = temp->link;
    }

    Prio_Node* temp2 = temp->link;

    temp->link = new_node;
    new_node->link = temp2;
}

int prioqueue_peek(Prio_Queue* q) {
    if (prioqueue_is_empty(q)) {
        printf("Priority Queue is Empty!\n");
        exit(1);
    }
    return q->front->val;
}

int priodequeue(Prio_Queue* q) {
    if (prioqueue_is_empty(q)) {
        printf("Priority Queue is Empty!\n");
        exit(1);
    }

    int tempv = q->front->val;

    Prio_Node* tempn = q->front;
    q->front = q->front->link;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(tempn);
    return tempv;
}

void prioqueue_print(Prio_Queue* q) {
    if (prioqueue_is_empty(q)) {
        printf("Priority Queue is Empty!\n");
        return;
    }

    Prio_Node* temp = q->front;

    while (temp != NULL) {
        printf(" %d (p=%d) |", temp->val, temp->p);
        temp = temp->link;
    }
    printf("\n");
}
