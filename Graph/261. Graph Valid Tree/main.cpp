#include <iostream>
#include <vector>

using namespace std;

class SetNode {
public:
    int data;
    int rank;
    shared_ptr<SetNode> parent;
    SetNode(int data, int rank, shared_ptr<SetNode> parent): data(data), rank(rank), parent(parent) {}
};

class DisjointSet {
private:
    void linkSet(shared_ptr<SetNode> node1, shared_ptr<SetNode> node2) {
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
    int numOfSets = 0;
    shared_ptr<SetNode> makeSet(int data) {
        shared_ptr<SetNode> newNode = make_shared<SetNode>(data, 0, nullptr);
        newNode->parent = newNode;
        numOfSets += 1;
        return newNode;
    }
    shared_ptr<SetNode> findSet(shared_ptr<SetNode> node) {
        if (node == nullptr) return nullptr;
        if (node->parent != node) {
            node->parent = findSet(node->parent);
        }
        return node->parent;
    }
    void unionSet(shared_ptr<SetNode> node1, shared_ptr<SetNode> node2) {
        linkSet(findSet(node1), findSet(node2));
        numOfSets -= 1;
    }
};

class Solution {
public:
    bool checkConnected(vector<vector<int>>& edges, int n) {
        shared_ptr<DisjointSet> newDisjointSet = make_shared<DisjointSet>();
        vector<shared_ptr<SetNode>> nodes;
        for (int i = 0; i < n; i++) {
            shared_ptr<SetNode> newNode = newDisjointSet->makeSet(i);
            nodes.push_back(newNode);
        }
        for (auto& edge: edges) {
            if (newDisjointSet->findSet(nodes[edge[0]]) != newDisjointSet->findSet(nodes[edge[1]])) {
                newDisjointSet->unionSet(nodes[edge[0]], nodes[edge[1]]);
            }
        }
        return (newDisjointSet->numOfSets == 1)? true: false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        return ((m == n - 1) && checkConnected(edges, n));
    }
};

int main(void) {
    int numNodes;
    cin >> numNodes;
    int numEdges;
    cin >> numEdges;
    vector<vector<int>> edges(numEdges, vector<int>(2));
    for (int i = 0; i < numEdges; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    Solution sol;
    cout << sol.validTree(numNodes, edges) << endl;
    return 0;
}