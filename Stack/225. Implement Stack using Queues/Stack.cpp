#include "Stack.h"

MyListNode::MyListNode(int data): data(data), next(nullptr) {}

Queue::Queue(): len(0) {
    std::shared_ptr newNode = std::make_shared<MyListNode>(-1);
    head = newNode;
    tail = newNode;
}

bool Queue::empty() {
    return (len <= 0);
}

void Queue::enqueue(int data) {
    std::shared_ptr newNode = std::make_shared<MyListNode>(data);
    tail->next = newNode;
    tail = newNode;
    len++;
}

int Queue::peek() {
    if (empty()) {
        std::cout << "The queue is empty!!!" << std::endl;
        return -1;
    }
    return (head->next->data);
}

int Queue::dequeue() {
    if (empty()) {
        std::cout << "The queue is empty!!!" << std::endl;
        return -1;
    }
    len--;
    int data = head->next->data;
    head->next = head->next->next;
    if (len == 0) tail = head;
    return data;
}

MyStack::MyStack(): len(0) {
    for (int i = 0; i < 2; i++) queues[i] = std::make_shared<Queue>();
}

bool MyStack::empty() {
    return (len <= 0);
}

void MyStack::push(int data) {
    queues[1]->enqueue(data);
    while (!queues[0]->empty()) {
        queues[1]->enqueue(queues[0]->dequeue());
    }
    std::shared_ptr<Queue> temp = queues[0];
    queues[0] = queues[1];
    queues[1] = temp;
    len++;
}

int MyStack::top() {
    if (empty()) {
        std::cout << "The stack is empty!!!" << std::endl;
        return -1;
    }
    return queues[0]->peek();
}

int MyStack::pop() {
    if (empty()) {
        std::cout << "The stack is empty!!!" << std::endl;
        return -1;
    }
    len--;
    return queues[0]->dequeue();
}