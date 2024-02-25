#include "Stack.h"

Stack::Stack(): top(-1) {
    for (int i = 0; i < MAX_STACK_SIZE; i++) arr[i] = 0;
}

void Stack::push(int data) {
    if (isFull()) {
        std::cout << "The stack is full!!!" << std::endl;
        return;
    }
    top++;
    arr[top] = data;
    return;
}

int Stack::pop() {
    if (isEmpty()) {
        std::cout << "The stack is empty!!!" << std::endl;
        return 0;
    }
    int data = arr[top];
    arr[top] = 0;
    top--;
    return data;
}

int Stack::peek() {
    if (isEmpty()) {
        std::cout << "The stack is empty!!!" << std::endl;
        return 0;
    }
    return arr[top];
}

void Stack::printStack() {
    if (isEmpty()) return;
    for (int i = 0; i <= top; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

bool Stack::isFull() {
    return ((top + 1) >= MAX_STACK_SIZE);
}

bool Stack::isEmpty() {
    return ((top + 1) <= 0);
}