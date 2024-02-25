#include "Stack.h"

Stack::Stack(): top(0), size(0) {
    std::shared_ptr<std::vector<int>> newArr = std::make_shared<std::vector<int>>();
    arr = newArr;
}

void Stack::push(int data) {
}

int Stack::pop() {
}

int Stack::peek() {
}

void Stack::printStack() {
}

bool Stack::isEmpty() {
}