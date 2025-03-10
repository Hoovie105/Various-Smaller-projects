#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int topofstack = -1;

void push(int element) {
    if (topofstack == MAX_SIZE - 1) {
        printf("Error: Stack is full\n");
        return;
    }
    stack[++topofstack] = element;
}

int pop() {
    if (topofstack == -1) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return stack[topofstack--];
}

int top() {
    if (topofstack == -1) {
        printf("Error: Stack is empty\n");
        return 0;
    }
    return stack[topofstack];
}

int size() {
    return topofstack + 1;
}

int isEmpty() {
    return topofstack == -1;
}

int main() {
    push(1);
    push(2);
    push(3);
    printf("Top element: %d\n", top());
    printf("Stack size: %d\n", size());
    printf("Stack empty: %d\n", isEmpty());
    pop();
    printf("Top element: %d\n", top());
    printf("Stack size: %d\n", size());
    printf("Stack empty: %d\n", isEmpty());
    pop();
    printf("Top element: %d\n", top());
    printf("Stack size: %d\n", size());
    printf("Stack empty: %d\n", isEmpty());
    pop();
    top();
   
    return 0;
}
