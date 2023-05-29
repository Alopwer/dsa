// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front;
    int rear;
    int size;
    int *items;
};

typedef struct Queue queue;

queue* createQueue(int size) {
    queue *q = (queue*) malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    q->size = size;
    q->items = (int*) malloc(size * sizeof(int));
    return q;
}

int isFull(queue *q) {
    return q->rear == q->size - 1;
}

int isEmpty(queue *q) {
    return q->front == -1;
}

void enqueue(queue *q, int value) {
    if (isFull(q)) return;
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("\nEnqueued value: %d", value);
}

void dequeue(queue *q) {
    if (isEmpty(q)) return;
    printf("\nDequeued value: %d", q->items[q->front]);
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
}

int main() {
    int size;
    scanf("%d", &size);
    queue *q = createQueue(size);
    dequeue(q);
    enqueue(q, 5);
    enqueue(q, 3);
    dequeue(q);
}