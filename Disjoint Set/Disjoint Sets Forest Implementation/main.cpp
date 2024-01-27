#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Node {
public:
    int data;
    int rank;
    shared_ptr<Node> parent;
    Node(int data, int rank, shared_ptr<Node> parent): data(data), rank(rank), parent(parent) {}
};

class DisjointSet {
private:
    void linkSet(shared_ptr<Node> node1, shared_ptr<Node> node2) {
        if (node1->rank > node2->rank) {
            node2->parent = node1;
        }
        else {
            node1->parent = node2;
            if (node1->rank == node2->rank) node2->rank += 1;
        }
        return;
    }
public:
    shared_ptr<Node> makeSet(int data) {
        shared_ptr<Node> newNode = make_shared<Node>(data, 0, nullptr);
        newNode->parent = newNode;
        return newNode;
    }
    shared_ptr<Node> findSet(shared_ptr<Node> node) {
        if (node == nullptr) return nullptr;
        if (node->parent != node) {
            node->parent = findSet(node->parent);
        }
        return node->parent;
    }
    void unionSet(shared_ptr<Node> node1, shared_ptr<Node> node2) {
        linkSet(findSet(node1), findSet(node2));
    }
};

void printRootOfEachSubTree(shared_ptr<DisjointSet> disjointSet, vector<shared_ptr<Node>>& nodes) {
    for (auto& node: nodes) {
        cout << disjointSet->findSet(node)->data << " ";
    }
    cout << endl;
    return;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    shared_ptr<DisjointSet> newDisjointSet = make_shared<DisjointSet>();
    vector<shared_ptr<Node>> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(newDisjointSet->makeSet(nums[i]));
    }
    printRootOfEachSubTree(newDisjointSet, nodes);
    newDisjointSet->unionSet(nodes[0], nodes[3]);
    newDisjointSet->unionSet(nodes[1], nodes[2]);
    newDisjointSet->unionSet(nodes[0], nodes[1]);
    printRootOfEachSubTree(newDisjointSet, nodes);
    return 0;
}