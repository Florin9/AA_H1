#include <stdio.h>
#include <stdlib.h>
int ERROR = -2147483648;

typedef struct MaxHeap {
    int capacity;
    int size;
    int *elem;
} MaxHeap;
typedef MaxHeap T;
#include "algo.h"

int parent(int i) {
    return (i-1)/2;
}
int leftchild(int i) {
    return (2*i+1);
}
int rightchild(int i) {
    return (2*i+2);
}
void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}
void* insert(void* heap1, int elem) {
	MaxHeap* heap = (MaxHeap*) heap1;
    if(heap->size-1 == heap->capacity) {
        int* x = (int*) realloc(heap->elem, 2*heap->capacity*sizeof(int));
        heap->elem = x;
        heap->capacity = 2*heap->capacity;
    }
    heap->elem[heap->size] = elem;
    int i = heap->size;
    heap->size++;
    while(i != 0 && heap->elem[parent(i)] < heap->elem[i]) {
        swap(&heap->elem[i], &heap->elem[parent(i)]);
        i = parent(i);
    }
    return heap;
}

void* initialize(int capacity) {
    MaxHeap* heap = (MaxHeap*) malloc(sizeof(MaxHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->elem = (int*) malloc(capacity * sizeof(int));
    return heap;
}

int getMax(void* heap1) {
	MaxHeap* heap = (MaxHeap*) heap1;
    if(heap == NULL) {
        return ERROR;
    }
    if(heap->elem == NULL || heap->size == 0) {
        return ERROR;
    }

    return heap->elem[0];
}

void siftDown(MaxHeap* heap, int i) {
    int l = leftchild(i);
    int r = rightchild(i);
    int largest = i;
    if(l < heap->size && heap->elem[l] > heap->elem[largest]) {
        largest = l;
    }
    if(r < heap->size && heap->elem[r] > heap->elem[largest]) {
        largest = r;
    }

    if(largest != i) {
        swap(&heap->elem[i], &heap->elem[largest]);
        siftDown(heap, largest);
    }




}

void* deleteMax(void* heap1) {
	MaxHeap* heap = (MaxHeap*) heap1;
    if(heap == NULL) {
        return NULL;
    }
    if(heap->elem == NULL) {
        return heap;
    }
    if(heap->size <= 0) {
        return heap;
    }
    heap->elem[0] = heap->elem[heap->size-1];
    heap->size--;
    siftDown(heap, 0);

    return heap;
}

