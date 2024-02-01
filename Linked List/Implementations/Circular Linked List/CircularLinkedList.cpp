#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList(): len(0) {        
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>();
    pseudoHead = newNode;
    tail = newNode;
};

void CircularLinkedList::insertToHead(int data) {
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>(data);
    if (len == 0) {
        pseudoHead->next = newNode;
        newNode->next = newNode;
        tail = newNode;
        len++;
        return;
    }
    newNode->next = pseudoHead->next;
    pseudoHead->next = newNode;
    tail->next = newNode;
    len++;
    return;
}

void CircularLinkedList::insertToTail(int data) {
    if (len == 0) {
        insertToHead(data);
        return;
    }
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>(data);
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
    len++;
    return;
}

void CircularLinkedList::insertAfterIdx(int data, int index) {
    if (index >= len) {
        std::cerr << "Index out of range!!!" << std::endl;
        return;
    }
    if (index == len - 1) {
        insertToTail(data);
        return;
    }
    int currentIndex = 0;
    std::shared_ptr<ListNode> currentNode = pseudoHead->next;
    while (currentIndex != index) {
        currentNode = currentNode->next;
        currentIndex++;
    }
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>(data);
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    len++;
}

void CircularLinkedList::insertBeforeIdx(int data, int index) {
    if (index >= len) {
        std::cerr << "Index out of range!!!" << std::endl;
        return;
    }
    if (index == 0) {
        insertToHead(data);
        return;
    }
    int currentIndex = 0;
    std::shared_ptr<ListNode> currentNode = pseudoHead->next;
    while (currentIndex != index - 1) {
        currentNode = currentNode->next;
        currentIndex++;
    }
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>(data);
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    len++;
}

void CircularLinkedList::removeHead() {
    if (len == 0) {
        std::cerr << "Linked List is empty!!!" << std::endl;
    }
    if (len == 1) {
        pseudoHead->next = nullptr;
        tail = pseudoHead;
        len--;
        return;
    }
    tail->next = pseudoHead->next->next;
    pseudoHead->next = pseudoHead->next->next;
    len--;
    return;
}

void CircularLinkedList::removeTail() {
    if (len == 0) {
        std::cerr << "Linked List is empty!!!" << std::endl;
    }
    if (len == 1) {
        pseudoHead->next = nullptr;
        tail = pseudoHead;
        len--;
        return;
    }
    int currentIndex = 0;
    std::shared_ptr<ListNode> currentNode = pseudoHead->next;
    for (int i = 0; i < len - 2; i++) {
        currentNode = currentNode->next;
    }
    tail = currentNode;
    tail->next = pseudoHead->next;
    len--;
}

void CircularLinkedList::traverse() {
    std::shared_ptr<ListNode> currentNode = pseudoHead->next;
    std::cout << "Len: " << len << std::endl;
    if (len > 0) std::cout << "Head: " << pseudoHead->next->data << " Tail: " << tail->data << " Next to tail: " << tail->next->data << std::endl;
    for (int i = 0; i < len; i++) {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

void CircularLinkedList::reverse() {
    if (len <= 1) return;
    std::shared_ptr<ListNode> prevNode = pseudoHead->next;
    std::shared_ptr<ListNode> currentNode = pseudoHead->next->next;
    tail = prevNode;
    for (int i = 0; i < len - 1; i++) {
        std::shared_ptr<ListNode> nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    tail->next = prevNode;
    pseudoHead->next = prevNode;
}