#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
    int data[MAX];
    int top;
} MyStack;


MyStack* myStackCreate() {
    MyStack *stack = (MyStack*)malloc(sizeof(MyStack));
    stack->top = -1;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    if (obj->top < MAX - 1) {
        obj->data[++obj->top] = x;
    } else {
        printf("Stack overflow\n");
    }
}

int myStackPop(MyStack* obj) {
    if (obj->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return obj->data[obj->top--];
}

int myStackTop(MyStack* obj) {
    if (obj->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return obj->data[obj->top];
}

bool myStackEmpty(MyStack* obj) {
    return obj->top == -1;
}

void myStackFree(MyStack* obj) {
    free(obj);
}
