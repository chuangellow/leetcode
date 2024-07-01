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
    int numGroups;
    DisjointSet(int n) : numNodes(n), numGroups(n) {
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
        Node *xP = findSet(x), *yP = findSet(y);
        if (xP != yP) {
            numGroups -= 1;
        }
        link(findSet(x), findSet(y));
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
            if (sets->numGroups == 1) return time;
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