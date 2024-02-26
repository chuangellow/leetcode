#include "Queue.h"

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
}

int Queue::dequeue() {
}

int Queue::getLen() {
}

int Queue::getFront() {
}

bool Queue::isEmpty() {
}

void Queue::showQueue() {
}