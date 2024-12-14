#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    int size;
};

struct LinkedList* createLinkedList() {
    struct LinkedList* linkedList = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    linkedList->head = NULL;
    linkedList->size = 0;
    return linkedList;
}

void addFirst(struct LinkedList* linkedList, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = linkedList->head;
    linkedList->head = newNode;
    linkedList->size++;
}

void removeFirst(struct LinkedList* linkedList) {
    if (linkedList->head == NULL) return;
    struct Node* temp = linkedList->head;
    linkedList->head = linkedList->head->next;
    free(temp);
    linkedList->size--;
}

void addLast(struct LinkedList* linkedList, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (linkedList->head == NULL) {
        linkedList->head = newNode;
        linkedList->size++;
        return;
    }
    struct Node* last = linkedList->head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    linkedList->size++;
}

void removeLast(struct LinkedList* linkedList) {
    if (linkedList->head == NULL) return;
    if (linkedList->head->next == NULL) {
        free(linkedList->head);
        linkedList->head = NULL;
        linkedList->size--;
        return;
    }
    struct Node* last = linkedList->head;
    while (last->next->next != NULL) {
        last = last->next;
    }
    free(last->next);
    last->next = NULL;
    linkedList->size--;
}

int getFirst(struct LinkedList* linkedList) {
    return linkedList->head->data;
}

int getLast(struct LinkedList* linkedList) {
    struct Node* last = linkedList->head;
    while (last->next != NULL) {
        last = last->next;
    }
    return last->data;
}

int size(struct LinkedList* linkedList) {
    return linkedList->size;
}

int main() {
    struct LinkedList* linkedList = createLinkedList();
    addFirst(linkedList, 10);
    addFirst(linkedList, 20);
    addLast(linkedList, 30);
    addLast(linkedList, 40);
    printf("%d", getFirst(linkedList));
    printf("%d", getLast(linkedList));
    removeLast(linkedList);
}
