#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int item;
    struct Node* next;
} Node;

typedef struct Queue{
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* q, int value){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->item = value;
    temp->next = NULL;
    if (q->front == NULL && q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Error: Queue is empty\n");
        return -1;
    } else {
        Node* temp = q->front;
        int value = temp->item;
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
        return value;
    }
}

void merge_sort(Queue* q){
    if (q->front == NULL || q->front == q->rear) {
        return;
    }
    Queue q1, q2;
    q1.front = q1.rear = q2.front = q2.rear = NULL;
    int i, size = 0;
    Node* curnode = q->front;
    while (curnode != NULL) {
        curnode = curnode->next;
        size++;
    }
    for (i = 0; i < size / 2; i++) {
        enqueue(&q1, dequeue(q));
    }
    while (q->front != NULL) {
        enqueue(&q2, dequeue(q));
    }
    merge_sort(&q1);
    merge_sort(&q2);
    while (q1.front != NULL && q2.front != NULL) {
        if (q1.front->item < q2.front->item) {
            enqueue(q, dequeue(&q1));
        } else {
            enqueue(q, dequeue(&q2));
        }
    }
    while (q1.front != NULL) {
        enqueue(q, dequeue(&q1));
    }
    while (q2.front != NULL) {
        enqueue(q, dequeue(&q2));
    }
}

int main(){
    Queue q;
    q.front = q.rear = NULL;
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i < n; i++) {
        enqueue(&q, arr[i]);
    }
    merge_sort(&q);
    while (q.front != NULL) {
        printf("%d ", dequeue(&q));
    }
    printf("\n");
    return 0;
}
