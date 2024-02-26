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
}

void Queue::enqueue(int data) {
    std::shared_ptr<QueueNode> newNode = std::make_shared<QueueNode>(data);
    newNode->next = pseudoHead->next;
    pseudoHead->next = newNode;
    len++;
    return;
}

int Queue::dequeue() {
    int data = pseudoHead->next->data;
    pseudoHead->next = pseudoHead->next->next;
    len--;
    return data;
}

int Queue::getLen() {
    return len;
}

int Queue::getFront() {
    return pseudoHead->next->data;
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