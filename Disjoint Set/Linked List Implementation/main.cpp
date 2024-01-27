#include <iostream>

using namespace std;

class Set;

class Node {
public:
    int data;
    Node* next;
    Set* representative;
    Node() {
        this->data = 0;
        this->next = nullptr;
        this->representative = nullptr;
    }
    Node(int data, Node* next, Set* representative) {
        this->data = data;
        this->next = next;
        this->representative = representative;
    }
};

class Set {
public:
    int len;
    Node* head;
    Node* tail;
    Set() {
        this->len = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }
    Set(Node* head, Node* tail) {
        this->len = 0;
        this->head = head;
        this->tail = tail;
    }
    void traverseSet() {
        if (len == 0) return;
        Node* currentNode = head;
        while (currentNode != nullptr) {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
        return;
    }
};

class DisjointSet {
public:
    Node* makeSet(int data) {
        Node* newNode = new Node(data, nullptr, nullptr);
        Set* newSet = new Set(newNode, newNode);
        newNode->representative = newSet;
        newSet->len = 1;
        return newNode;
    }
    void unionSet(Node* node1, Node* node2) {
        if (node1 == nullptr || node2 == nullptr) return;
        Set* s1 = node1->representative;
        Set* s2 = node2->representative;
        if (s1->len >= s2->len) {
            s1->len = s1->len + s2->len;
            s1->tail->next = s2->head;
            Node* currentNode = s2->head;
            while (currentNode != nullptr) {
                currentNode->representative = s1;
                currentNode = currentNode->next;
            }
            s1->tail = s2->tail;
            delete(s2);
        }
        else {
            s2->len = s1->len + s2->len;
            s2->tail->next = s1->head;
            Node* currentNode = s1->head;
            while (currentNode != nullptr) {
                currentNode->representative = s2;
                currentNode = currentNode->next;
            }
            s2->tail = s1->tail;
            delete(s1);
        }
        return;
    }
    Node* findSet(Node* node) {
        if (node == nullptr) return nullptr;
        return node->representative->head;
    }
};

int main(void) {
    DisjointSet newDisjointSet;
    Node* node1 = newDisjointSet.makeSet(1);
    Node* node2 = newDisjointSet.makeSet(2);
    Node* node3 = newDisjointSet.makeSet(3);
    newDisjointSet.unionSet(node1, node2);
    newDisjointSet.unionSet(node1, node3);
    Node* node4 = newDisjointSet.makeSet(4);
    Node* node5 = newDisjointSet.makeSet(5);
    newDisjointSet.unionSet(node4, node5);
    node3->representative->traverseSet();
    node4->representative->traverseSet();
    newDisjointSet.unionSet(node5, node1);
    node4->representative->traverseSet();
    return 0;
}