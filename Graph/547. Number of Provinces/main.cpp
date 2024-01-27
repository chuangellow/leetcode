#include <iostream>
#include <vector>
#include <queue>

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
    int numberOfSet = 0;
    shared_ptr<Node> makeSet(int data) {
        shared_ptr<Node> newNode = make_shared<Node>(data, 0, nullptr);
        newNode->parent = newNode;
        numberOfSet += 1;
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
        numberOfSet -= 1;
    }
};

class Solution {
public:
    typedef struct vectex {
        int idx;
        int color; // 0: white, 1: gray, 2: black
    } vertex;
    void DFSVisit(int sourceIdx, vector<vertex>& vertices, vector<vector<int>>& isConnected, int n) {
        vertices[sourceIdx].color = 1;
        for (int i = 0; i < n; i++) {
            if (i == sourceIdx) continue;
            if (isConnected[sourceIdx][i]) {
                if (vertices[i].color == 0) {
                    DFSVisit(i, vertices, isConnected, n);
                }
            }
        }
        vertices[sourceIdx].color = 2;
        return;
    }
    int DFS(vector<vertex>& vertices, vector<vector<int>>& isConnected, int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (vertices[i].color == 0) {
                DFSVisit(i, vertices, isConnected, n);
                count++;
            }
        }
        return count;
    }
    void BFS(int sourceIdx, vector<vertex>& vertices, vector<vector<int>>& isConnected, int n) {
        vertices[sourceIdx].color = 1;
        vertex source = vertices[sourceIdx];
        queue<vertex> nextVisit;
        nextVisit.push(source);
        while (nextVisit.size() != 0) {
            vertex u = nextVisit.front();
            nextVisit.pop();
            for (int i = 0; i < n; i++) {
                if (i == u.idx) continue;
                if (isConnected[u.idx][i]) {
                    if (vertices[i].color == 0) {
                        vertices[i].color = 1;
                        nextVisit.push(vertices[i]);
                    }
                }
            }
            vertices[u.idx].color = 2;
        }
        return;
    }
    int connectedComponent(vector<vector<int>>& isConnected, int n) {
        vector<shared_ptr<Node>> vertices;
        DisjointSet newDisjointSet;
        for (int i = 0; i < n; i++) {
            shared_ptr<Node> vertex = newDisjointSet.makeSet(i);
            vertices.push_back(vertex);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isConnected[i][j] && (newDisjointSet.findSet(vertices[i]) != newDisjointSet.findSet(vertices[j]))) {
                    newDisjointSet.unionSet(vertices[i], vertices[j]);
                }
            }
        }
        return newDisjointSet.numberOfSet;
    }
    int findNonVisited(vector<vertex>& vertices, int n) {
        for (int i = 0; i < n; i++) {
            if (vertices[i].color == 0) return i;
        }
        return -1;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        return connectedComponent(isConnected, n);
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> isConnected(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }
    Solution sol;
    cout << sol.findCircleNum(isConnected) << endl;
    return 0;
}