#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList(): len(0) {        
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>();
    pseudoHead = newNode;
    pseudoTail = newNode;
};

void DoubleLinkedList::insertToHead(int data) {
}

void DoubleLinkedList::insertToTail(int data) {
}

void DoubleLinkedList::insertAfterIdxFromHead(int data, int index) {
}

void DoubleLinkedList::insertBeforeIdxFromHead(int data, int index) {
}

void DoubleLinkedList::removeHead() {
}

void DoubleLinkedList::removeTail() {
}

void DoubleLinkedList::traverseFromHead() {
}

void DoubleLinkedList::traverseFromTail() {
}

void DoubleLinkedList::reverse() {
}