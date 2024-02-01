#include <vector>
#include <iostream>
#include <memory>

class ListNode {
public:
    int data;
    std::shared_ptr<ListNode> prev;
    std::shared_ptr<ListNode> next;
    ListNode(): data(-1), next(nullptr) {}
    ListNode(int data): data(data), prev(nullptr), next(nullptr) {}
    ListNode(int data, std::shared_ptr<ListNode> prev, std::shared_ptr<ListNode> next): data(data), prev(prev), next(next) {}
};

class DoubleLinkedList {
public:
    std::shared_ptr<ListNode> pseudoHead;
    std::shared_ptr<ListNode> pseudoTail;
    int len;
    DoubleLinkedList();
    void insertToHead(int data);
    void insertToTail(int data);
    void insertAfterIdxFromHead(int data, int index);
    void insertBeforeIdxFromHead(int data, int index);
    void removeHead();
    void removeTail();
    void traverseFromHead();
    void traverseFromTail();
    void reverse();
};