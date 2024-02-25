#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList(): len(0) {        
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>();
    pseudoHead = newNode;
    pseudoTail = newNode;
};

void DoubleLinkedList::insertToHead(int data) {
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>(data);
    if (len == 0) {
        pseudoHead->next = newNode;
        pseudoTail->prev = newNode;
        newNode->next = pseudoTail;
        newNode->prev = pseudoHead;
        len++;
        return;
    }
    pseudoHead->next->prev = newNode;
    newNode->next = pseudoHead->next;
    pseudoHead->next = newNode;
    newNode->prev = pseudoHead;
    len++;
    return;
}

void DoubleLinkedList::insertToTail(int data) {
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>(data);
    if (len == 0) {
        pseudoHead->next = newNode;
        pseudoTail->prev = newNode;
        len++;
        return;
    }
    pseudoTail->prev->next = newNode;
    newNode->prev = pseudoTail->prev;
    newNode->next = pseudoTail;
    pseudoTail->prev = newNode;
    len++;
    return;
}

void DoubleLinkedList::insertAfterIdxFromHead(int data, int index) {
    // Assume user will use this operation even if the list is empty
    if (len == 0) {
        insertToHead(data);
        return;
    }
    if (index >= len) {
        std::cout << "Index out of range!!!" << std::endl;
        return;
    }
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>(data);
    // We can optimize the searching process by determining whether to search from head or tail.
    int currentIdx = 0;
    std::shared_ptr<ListNode> currentNode = pseudoHead->next;
    std::shared_ptr<ListNode> nextNode = pseudoHead->next->next;
    while (currentIdx != index) {
        currentNode = currentNode->next;
        nextNode = nextNode->next;
        currentIdx++;
    }
    newNode->prev = currentNode;
    newNode->next = nextNode;
    currentNode->next = newNode;
    nextNode->prev = newNode;
    len++;
    return;
}

void DoubleLinkedList::insertBeforeIdxFromHead(int data, int index) {
    // Assume user will use this operation even if the list is empty
    if (len == 0) {
        insertToHead(data);
        return;
    }
    if (index >= len) {
        std::cout << "Index out of range!!!" << std::endl;
        return;
    }
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>(data);
    // We can optimize the searching process by determining whether to search from head or tail.
    int currentIdx = 0;
    std::shared_ptr<ListNode> prevNode = pseudoHead;
    std::shared_ptr<ListNode> currentNode = pseudoHead->next;
    while (currentIdx != index) {
        prevNode = prevNode->next;
        currentNode = currentNode->next;
        currentIdx++;
    }
    newNode->prev = prevNode;
    newNode->next = currentNode;
    prevNode->next = newNode;
    currentNode->prev = newNode;
    len++;
    return;
}

void DoubleLinkedList::removeHead() {
    if (len == 0) {
        std::cout << "The List is empty!!!" << std::endl;
        return;
    }
    std::shared_ptr<ListNode> prevNode = pseudoHead;
    std::shared_ptr<ListNode> nextNode = pseudoHead->next->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    len--;
    return;
}

void DoubleLinkedList::removeTail() {
    if (len == 0) {
        std::cout << "The List is empty!!!" << std::endl;
        return;
    }
    std::shared_ptr<ListNode> prevNode = pseudoTail->prev->prev;
    std::shared_ptr<ListNode> nextNode = pseudoTail;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    len--;
    return;
}

void DoubleLinkedList::traverseFromHead() {
    if (len == 0) {
        std::cout << "The List is empty!!!" << std::endl;
        return;
    }
    std::shared_ptr<ListNode> currentNode = pseudoHead->next;
    std::cout << "Len: " << len << std::endl;
    while (currentNode && currentNode != pseudoTail) {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
    return;
}

void DoubleLinkedList::traverseFromTail() {
    if (len == 0) {
        std::cout << "The List is empty!!!" << std::endl;
        return;
    }
    std::shared_ptr<ListNode> currentNode = pseudoTail->prev;
    std::cout << "Len: " << len << std::endl;
    while (currentNode && currentNode != pseudoHead) {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->prev;
    }
    std::cout << std::endl;
    return;
}