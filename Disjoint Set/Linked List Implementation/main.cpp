#include <iostream>
#include <memory>

using namespace std;

class Set;

class Node {
public:
    int data;
    shared_ptr<Node> next;
    shared_ptr<Set> representative;
    Node(int data, shared_ptr<Node> next, shared_ptr<Set> representative)
        : data(data), next(next), representative(representative) {}
};

class Set {
public:
    int len;
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    Set(shared_ptr<Node> head, shared_ptr<Node> tail)
        : head(head), tail(tail) {}
    void traverseSet() {
        if (len == 0) return;
        shared_ptr<Node> currentNode = head;
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
    shared_ptr<Node> makeSet(int data) {
        shared_ptr<Node> newNode = make_shared<Node>(data, nullptr, nullptr);
        shared_ptr<Set> newSet = make_shared<Set>(newNode, newNode);
        newNode->representative = newSet;
        newSet->len = 1;
        return newNode;
    }
    void unionSet(shared_ptr<Node> node1, shared_ptr<Node> node2) {
        if (node1 == nullptr || node2 == nullptr) return;
        shared_ptr<Set> s1 = node1->representative;
        shared_ptr<Set> s2 = node2->representative;
        if (s1->len >= s2->len) {
            s1->len = s1->len + s2->len;
            s1->tail->next = s2->head;
            shared_ptr<Node> currentNode = s2->head;
            while (currentNode != nullptr) {
                currentNode->representative = s1;
                currentNode = currentNode->next;
            }
            s1->tail = s2->tail;
        }
        else {
            s2->len = s1->len + s2->len;
            s2->tail->next = s1->head;
            shared_ptr<Node> currentNode = s1->head;
            while (currentNode != nullptr) {
                currentNode->representative = s2;
                currentNode = currentNode->next;
            }
            s2->tail = s1->tail;
        }
        return;
    }
    shared_ptr<Node> findSet(shared_ptr<Node> node) {
        if (node == nullptr) return nullptr;
        return node->representative->head;
    }
};

int main(void) {
    DisjointSet newDisjointSet;
    shared_ptr<Node> node1 = newDisjointSet.makeSet(1);
    shared_ptr<Node> node2 = newDisjointSet.makeSet(2);
    shared_ptr<Node> node3 = newDisjointSet.makeSet(3);
    newDisjointSet.unionSet(node1, node2);
    newDisjointSet.unionSet(node1, node3);
    shared_ptr<Node> node4 = newDisjointSet.makeSet(4);
    shared_ptr<Node> node5 = newDisjointSet.makeSet(5);
    newDisjointSet.unionSet(node4, node5);
    node3->representative->traverseSet();
    node4->representative->traverseSet();
    newDisjointSet.unionSet(node5, node1);
    node4->representative->traverseSet();
    return 0;
}