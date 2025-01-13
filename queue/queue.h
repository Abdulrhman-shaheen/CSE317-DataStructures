#include <stdio.h>
#include <stdlib.h>

// ================== Array-Based Queue ==================
typedef struct queue {
    int front;
    int rear;
    int MAX;
    int* queue;
} Queue;

// Function prototypes for Array-Based Queue
void init_queue(Queue* q, int sz);
int queue_is_empty(Queue* q);
int queue_is_full(Queue* q);
void enqueue(Queue* q, int a);
int queue_peek(Queue* q);
int dequeue(Queue* q);
void queue_print(Queue* q);

// ================== Linked List-Based Queue ==================
typedef struct node {
    int val;
    struct node* link;
} Node;

typedef struct llqueue {
    Node* front;
    Node* rear;
} llQueue;

// Function prototypes for Linked List-Based Queue
void init_llqueue(llQueue* q);
int llqueue_is_empty(llQueue* q);
void llenqueue(llQueue* q, int a);
int llqueue_peek(llQueue* q);
int lldequeue(llQueue* q);
void llqueue_print(llQueue* q);

// ================== Priority Queue ==================
typedef struct prio_node {
    int val;
    int p;  // Priority
    struct prio_node* link;
} Prio_Node;

typedef struct prio_queue {
    Prio_Node* front;
    Prio_Node* rear;
} Prio_Queue;

// Function prototypes for Priority Queue
void init_prioqueue(Prio_Queue* q);
int prioqueue_is_empty(Prio_Queue* q);
void prioenqueue(Prio_Queue* q, int a, int p);
int prioqueue_peek(Prio_Queue* q);
int priodequeue(Prio_Queue* q);
void prioqueue_print(Prio_Queue* q);