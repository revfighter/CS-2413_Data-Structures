#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* q1;
    int* q2;
    int front1, rear1, size1;
    int front2, rear2, size2;
    int capacity;
} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->capacity = 100;
    stack->q1 = (int*)malloc(stack->capacity * sizeof(int));
    stack->q2 = (int*)malloc(stack->capacity * sizeof(int));
    stack->front1 = 0;
    stack->rear1 = -1;
    stack->size1 = 0;
    stack->front2 = 0;
    stack->rear2 = -1;
    stack->size2 = 0;
    return stack;
}


bool isEmptyQueue(int size) {
    return size == 0;
}


void enqueue(int* queue, int* rear, int* size, int capacity, int x) {
    if (*size < capacity) {
        queue[++(*rear)] = x;
        (*size)++;
    }
}


int dequeue(int* queue, int* front, int* size) {
    if (*size > 0) {
        int val = queue[*front];
        (*front)++;
        (*size)--;
        return val;
    }
    return -1; 
}


void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q2, &obj->rear2, &obj->size2, obj->capacity, x);
    
    
    while (!isEmptyQueue(obj->size1)) {
        enqueue(obj->q2, &obj->rear2, &obj->size2, obj->capacity, dequeue(obj->q1, &obj->front1, &obj->size1));
    }

 
    int* tempQ = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = tempQ;

  
    int tempFront = obj->front1;
    obj->front1 = obj->front2;
    obj->front2 = tempFront;

    int tempRear = obj->rear1;
    obj->rear1 = obj->rear2;
    obj->rear2 = tempRear;

    int tempSize = obj->size1;
    obj->size1 = obj->size2;
    obj->size2 = tempSize;
}


int myStackPop(MyStack* obj) {
    return dequeue(obj->q1, &obj->front1, &obj->size1);
}


int myStackTop(MyStack* obj) {
    return obj->q1[obj->front1];
}


bool myStackEmpty(MyStack* obj) {
    return isEmptyQueue(obj->size1);
}


void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}
