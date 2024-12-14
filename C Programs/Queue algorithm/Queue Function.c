#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int value;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    return node;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}

bool isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

void enqueue(struct Queue* queue, int value) {
    struct Node* node = newNode(value);
    if (queue->rear == NULL) {
        queue->front = queue->rear = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
    queue->size++;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    struct Node* temp = queue->front;
    int value = temp->value;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return value;
}

int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue->front->value;
}

int size(struct Queue* queue) {
    return queue->size;
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("Front item is %d\n", front(queue));

    printf("Dequeued item is %d\n", dequeue(queue));
    printf("Front item is %d\n", front(queue));
    printf("Dequeued item is %d\n", dequeue(queue));
    printf("Queue size is %d\n", size(queue));
    printf("Front item is %d\n", front(queue));

    return 0;
}
