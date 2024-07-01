#include <vector>
#include <iostream>

using namespace std;

class Node {
public:
    Node *parent;
    int idx;
    int rank;
    Node(int idx) : parent(this), idx(idx), rank(0) {}
};

class DisjointSet {
public:
    Node **nodes;
    int numNodes;
    DisjointSet(int n) : numNodes(n) {
        nodes = new Node*[numNodes];
        for (int i = 0; i < numNodes; i++) {
            nodes[i] = new Node(i);
        }
    }
    Node *findSet(Node *x) {
        if (x != x->parent) {
            x->parent = findSet(x->parent);
        }
        return x->parent;
    }
    void link(Node *x, Node *y) {
        if (x->rank > y->rank) {
            y->parent = x;
        }
        else {
            x->parent = y;
            if (x->rank == y->rank) {
                y->rank += 1;
            }
        }
    }
    void unionSets(Node *x, Node *y) {
        link(findSet(x), findSet(y));
    }
    bool checkConnected() {
        Node *representive = findSet(nodes[0]);
        for (int i = 1; i < numNodes; i++) {
            if (findSet(nodes[i]) != representive) return false;
        }
        return true;
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        int m = logs.size();
        DisjointSet *sets = new DisjointSet(n);
        for (int i = 0; i < m; i++) {
            int time = logs[i][0];
            sets->unionSets(sets->nodes[logs[i][1]], sets->nodes[logs[i][2]]);
            if (sets->checkConnected()) return time;
        }
        return -1;
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> logs(m);
    for (int i = 0; i < m; i++) {
        vector<int> log(3);
        cin >> log[0] >> log[1] >> log[2];
        logs[i] = log;
    }
    Solution sol;
    sol.earliestAcq(logs, n);
    return 0;
}