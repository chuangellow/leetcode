#include "LinkedList.h"

LinkedList::LinkedList(): len(0) {        
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>();
    pseudoHead = newNode;
    tail = newNode;
};    

void LinkedList::insertToHead(int data) {
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>(data);
    if (pseudoHead->next == nullptr) {
        pseudoHead->next = newNode;
        tail = newNode;
        len = 1;
        return;
    }
    newNode->next = pseudoHead->next;
    pseudoHead->next = newNode;
    len++;
    return;
}

void LinkedList::insertToTail(int data) {
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>(data);
    if (pseudoHead->next == nullptr) {
        pseudoHead->next = newNode;
        tail = newNode;
        len = 1;
        return;
    } 
    tail->next = newNode;
    tail = newNode;
    len++;
    return;
}

void LinkedList::insertAfterIdx(int data, int index) {
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>(data);
    if (index >= len) {
        std::cerr << "Index out of range!!!" << std::endl;
        return;
    }
    else if (index == len - 1) {
        insertToTail(data);
        return;
    }
    int currentIndex = 0;
    std::shared_ptr<ListNode> currentNode = pseudoHead->next;
    while (currentNode != nullptr && currentIndex != index) {
        currentNode = currentNode->next;
        currentIndex++;
    }
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    len++;
    return;
}

void LinkedList::insertBeforeIdx(int data, int index) {
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>(data);
    if (index >= len) {
        std::cerr << "Index out of range!!!" << std::endl;
        return;
    }
    else if (index == 0) {
        insertToHead(data);
        return;
    }
    int currentIndex = 0;
    std::shared_ptr<ListNode> currentNode = pseudoHead;
    while (currentNode != nullptr && currentIndex != index) {
        currentNode = currentNode->next;
        currentIndex++;
    }
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    len++;
    return;
}

void LinkedList::removeHead() {
    if (pseudoHead->next == nullptr) {
        std::cerr << "Linked List is empty!!!" << std::endl;
        return;
    }
    pseudoHead->next = pseudoHead->next->next;
    len--;
    return;
}

void LinkedList::removeTail() {
    if (pseudoHead->next == nullptr) {
        std::cerr << "Linked List is empty!!!" << std::endl;
        return;
    }
    std::shared_ptr<ListNode> currentNode = pseudoHead;
    while (currentNode->next != nullptr && currentNode->next != tail) currentNode = currentNode->next;
    currentNode->next = tail->next;
    tail = currentNode;
    len--;
    return;
}

int LinkedList::getData(int index) {
    if (len == 0) {
        std::cerr << "Linked List is empty!!!" << std::endl;
        return -1;
    }
    else if (index >= len) {
        std::cerr << "Index out of range!!!" << std::endl;
        return -1;
    }
    int currentIndex = 0;
    std::shared_ptr<ListNode> currentNode = pseudoHead->next;
    while (currentNode != nullptr && currentIndex != index) {
        currentIndex++;
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

void LinkedList::traverse() {
    std::shared_ptr<ListNode> currentNode = pseudoHead->next;
    std::cout << "Len: " << len << std::endl;
    while (currentNode != nullptr) {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

void LinkedList::reverse() {
    if (len == 0) {
        std::cerr << "Linked List is empty!!!" << std::endl;
        return;
    }
    else if (len == 1) return;
    std::shared_ptr<ListNode> prevNode = pseudoHead->next;
    std::shared_ptr<ListNode> currentNode = pseudoHead->next->next;
    prevNode->next = nullptr;
    tail = pseudoHead->next;
    while (currentNode != nullptr) {
        std::shared_ptr<ListNode> nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    pseudoHead->next = prevNode;
}