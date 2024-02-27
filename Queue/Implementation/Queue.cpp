#include "Queue.h"
#include <iostream>

QueueNode::QueueNode(): 
    data(0), next(nullptr) {
}

QueueNode::QueueNode(int data):
    data(data), next(nullptr) {
}

Queue::Queue(): 
    len(0) {
        std::shared_ptr<QueueNode> newNode = std::make_shared<QueueNode>();
        pseudoHead = newNode;
        tail = newNode;
}

void Queue::enqueue(int data) {
    std::shared_ptr<QueueNode> newNode = std::make_shared<QueueNode>(data);
    newNode->next = pseudoHead->next;
    pseudoHead->next = newNode;
    len++;
    if (len == 1) tail = newNode;
    return;
}

int Queue::dequeue() {
    int data = tail->data;
    std::shared_ptr<QueueNode> currentNode = pseudoHead;
    while (currentNode->next != tail) {
        currentNode = currentNode->next;
    }
    tail = currentNode;
    currentNode->next = nullptr;
    len--;
    return data;
}

int Queue::getLen() {
    return len;
}

int Queue::getFront() {
    return tail->data;
}

bool Queue::isEmpty() {
    return (len <= 0);
}

void Queue::printQueue() {
    if (isEmpty()) return;
    std::shared_ptr<QueueNode> currentNode = pseudoHead->next;
    while (currentNode) {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}