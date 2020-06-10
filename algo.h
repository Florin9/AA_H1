
#ifndef ALGO_H
#define ALGO_H

//T - type to be declared when using
//typedef struct MaxHeap {
//    int capacity;
//    int size;
//    int *elem;
//} MaxHeap;


void* insert(void* root, int elem) ;

int getMax(void* root);

void* deleteMax(void* root);

void* initialize(int nr);
#endif // ALGO_H_
