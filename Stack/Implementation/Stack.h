#include <vector>
#include <iostream>

#define MAX_STACK_SIZE 4096

class Stack {
private:
    int arr[MAX_STACK_SIZE];
    int top;
public:
    Stack();
    void push(int data);
    int pop();
    int peek();
    void printStack();
    bool isEmpty();
    bool isFull();
};