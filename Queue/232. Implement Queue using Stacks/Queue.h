#include <iostream>

struct ListNode {
    int data;
    std::shared_ptr<ListNode> next;
    ListNode(int data);
};

class Stack {
private:
    std::shared_ptr<ListNode> top;
    int len;
public:
    Stack();
    int pop();
    void push(int data);
    bool empty();
    int peek();
};

class MyQueue {
private:
    std::shared_ptr<Stack> stacks[2];
    int len;
public:
    MyQueue();
    void push(int x);
    int pop();
    int peek();
    bool empty();
};