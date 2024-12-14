#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<time.h>

#define MAX_HEAP_SIZE 100000000

typedef struct {
    int heap[MAX_HEAP_SIZE];
    int size;
} Heap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Heap *CreateParent() {
    Heap *heap = malloc(sizeof(Heap));
    heap->size = 0;
    return heap;
}

void insert(Heap *heap, int value) {
    heap->heap[heap->size] = value;
    int i = heap->size;

    while (i > 0 && heap->heap[i] < heap->heap[(i-1)/2]) {
        swap(&heap->heap[i], &heap->heap[(i-1)/2]);
        i = (i-1)/2;
    }

    heap->size++;
}

int RemoveMin(Heap *heap) {
    int min = heap->heap[0];
    heap->heap[0] = heap->heap[heap->size-1];
    heap->size--;

    int i = 0;
    while (i*2+1 < heap->size) {
        int child;
        if (i*2+2 == heap->size || heap->heap[i*2+1] < heap->heap[i*2+2]) {
            child = i*2+1;
        } else {
            child = i*2+2;
        }

        if (heap->heap[i] > heap->heap[child]) {
            swap(&heap->heap[i], &heap->heap[child]);
            i = child;
        } else {
            break;
        }
    }

    return min;
}

int min(Heap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return 1;
    }
    return heap->heap[0];
}

int size(Heap *heap) {
    return heap->size;
}

int isEmpty(Heap *heap) {
    return heap->size == 0;
}

void heapSort(int arr[], int n) {
    Heap *heap = CreateParent();

    for (int i = 0; i < n; i++) {
        insert(heap, arr[i]);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = RemoveMin(heap);
    }

    free(heap);
}

int main() {
     int n=60;
     int arr[n];
     srand(time(0));
        
        for (int i = 0; i < n; i++)
            arr[i] = rand()%1000;

        printf("Unsorted, size %d: ", n);
        for (int i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
    clock_t start = clock();

    heapSort(arr, n);
    
    clock_t end = clock();
    double timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Sorted, size %d in %f seconds\n", n, timeUsed);
}
