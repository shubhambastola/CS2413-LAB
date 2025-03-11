#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    int* array;
    int top;
    int capacity;
} Stack;


Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}


bool isStackEmpty(Stack* stack) {
    return stack->top == -1;
}


void pushToStack(Stack* stack, int item) {

    if (stack->top == stack->capacity - 1) {
        stack->capacity *= 2;
        stack->array = (int*)realloc(stack->array, stack->capacity * sizeof(int));
    }
    stack->array[++stack->top] = item;
}


int popFromStack(Stack* stack) {
    if (isStackEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}


int peekStack(Stack* stack) {
    if (isStackEmpty(stack))
        return -1;
    return stack->array[stack->top];
}


typedef struct {
    Stack* stack1;
    Stack* stack2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stack1 = createStack(10);
    queue->stack2 = createStack(10);
    return queue;
}


void myQueuePush(MyQueue* obj, int x) {
    pushToStack(obj->stack1, x);
}


void transfer(MyQueue* obj) {
    if (isStackEmpty(obj->stack2)) {
        while (!isStackEmpty(obj->stack1)) {
            pushToStack(obj->stack2, popFromStack(obj->stack1));
        }
    }
}


int myQueuePop(MyQueue* obj) {
    transfer(obj);
    return popFromStack(obj->stack2);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    transfer(obj);
    return peekStack(obj->stack2);
}

bool myQueueEmpty(MyQueue* obj) {
    return isStackEmpty(obj->stack1) && isStackEmpty(obj->stack2);
}


void myQueueFree(MyQueue* obj) {
    free(obj->stack1->array);
    free(obj->stack1);
    free(obj->stack2->array);
    free(obj->stack2);
    free(obj);
}