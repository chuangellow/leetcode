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

void LinkedList::traverse() {
    std::shared_ptr<ListNode> currentNode = pseudoHead->next;
    while (currentNode != nullptr) {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}