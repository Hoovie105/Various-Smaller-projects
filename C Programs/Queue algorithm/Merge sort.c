#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int data[MAX_SIZE];
    int front, rear;
};

struct Queue *createQueue() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = 0;
    return q;
}

int isEmpty(struct Queue *q) {
    return (q->front == q->rear);
}

void enqueue(struct Queue *q, int value) {
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_SIZE;
}

int dequeue(struct Queue *q) {
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return value;
}

void merge(struct Queue *a, struct Queue *b, struct Queue *s) {
    while (!isEmpty(a) && !isEmpty(b)) {
        if (a->data[a->front] < b->data[b->front]) {
            enqueue(s, dequeue(a));
        } else {
            enqueue(s, dequeue(b));
        }
    }
    while (!isEmpty(a)) {
        enqueue(s, dequeue(a));
    }
    while (!isEmpty(b)) {
        enqueue(s, dequeue(b));
    }
}

int main() {
   struct Queue *a = createQueue();
   struct Queue *b = createQueue();
   struct Queue *s = createQueue();

    enqueue(a, 1);
    enqueue(a, 3);
    enqueue(a, 5);

    enqueue(b, 2);
    enqueue(b, 4);
    enqueue(b, 6);

    merge(a, b, s);

    while (!isEmpty(s)) {
        printf("%d\n", dequeue(s));
    }

    return 0;
}
/*The program runs in O(n) time. the Queue portion of the code runs in O(1) as it features no looping
while the merge function runs in O(n)*/
