#include "Queue.h"

ListNode::ListNode(int data): data(data), next(nullptr) {}

Stack::Stack(): len(0) {
    top = std::make_shared<ListNode>(-1);
}

bool Stack::empty() { return (len < 1); }

void Stack::push(int data) {
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>(data);
    newNode->next = top;
    top = newNode;
    len++;
}

int Stack::pop() {
    if (empty()) {
        std::cout << "The stack is empty!!!" << std::endl;
        return;
    }
    int data = top->data;
    top = top->next;
    len--;
    return data;
}

int Stack::peek() { return top->data; }

MyQueue::MyQueue() : len(0) {
    for (int i = 0; i < 2; i++) stacks[i] = std::make_shared<Stack>();
}

bool MyQueue::empty() { return (len < 1); }

void MyQueue::push(int data) {
    while (!stacks[0]->empty()) {
        stacks[1]->push(stacks[0]->pop());
    }
    stacks[0]->push(data);
    while (!stacks[1]->empty()) {
        stacks[0]->push(stacks[1]->pop());
    }
    len++;
}

int MyQueue::pop() {
    if (empty()) {
        std::cout << "The queue is empty!!!" << std::endl;
        return;
    }
    len--;
    return stacks[0]->pop();
}

int MyQueue::peek() {
    if (empty()) {
        std::cout << "The queue is empty!!!" << std::endl;
        return;
    }
    return stacks[0]->peek();
}