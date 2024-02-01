#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList(): len(0) {        
    std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>();
    pseudoHead = newNode;
    tail = newNode;
};    

void CircularLinkedList::insertToHead(int data) {
}

void CircularLinkedList::insertToTail(int data) {
}

void CircularLinkedList::insertAfterIdx(int data, int index) {
}

void CircularLinkedList::insertBeforeIdx(int data, int index) {
}

void CircularLinkedList::removeHead() {
}

void CircularLinkedList::removeTail() {
}

int CircularLinkedList::getData(int index) {
}

void CircularLinkedList::traverse() {
}

void CircularLinkedList::reverse() {
}