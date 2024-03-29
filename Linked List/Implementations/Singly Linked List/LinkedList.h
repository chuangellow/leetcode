#include <vector>
#include <iostream>
#include <memory>

class ListNode {
public:
    int data;
    std::shared_ptr<ListNode> next;
    ListNode(): data(-1), next(nullptr) {}
    ListNode(int data): data(data), next(nullptr) {}
};

class LinkedList {
public:
    std::shared_ptr<ListNode> pseudoHead;
    std::shared_ptr<ListNode> tail;
    int len;
    LinkedList();
    void insertToHead(int data);
    void insertToTail(int data);
    void insertAfterIdx(int data, int index);
    void insertBeforeIdx(int data, int index);
    void removeHead();
    void removeTail();
    int getData(int index);
    void traverse();
    void reverse();
};