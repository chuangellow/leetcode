#include <iostream>

struct MyListNode {
    int data;
    std::shared_ptr<MyListNode> next;
    MyListNode(int data);
};

class Queue {
private:
    std::shared_ptr<MyListNode> head;
    std::shared_ptr<MyListNode> tail;
    int len;
public:
    Queue();
    void enqueue(int data);
    int dequeue();
    int peek();
    bool empty();
};

class MyStack {
private:
    std::shared_ptr<Queue> queues[2];
    int len;
public:
    MyStack();
    void push(int x);
    int pop();
    int top();
    bool empty();
};