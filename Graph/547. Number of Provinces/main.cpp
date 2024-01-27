#include <iostream>
#include <vector>
#include <queue>

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
    int numberOfSet = 0;
    shared_ptr<Node> makeSet(int data) {
        shared_ptr<Node> newNode = make_shared<Node>(data, nullptr, nullptr);
        shared_ptr<Set> newSet = make_shared<Set>(newNode, newNode);
        newNode->representative = newSet;
        newSet->len = 1;
        numberOfSet += 1;
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
        numberOfSet -= 1;
        return;
    }
    shared_ptr<Node> findSet(shared_ptr<Node> node) {
        if (node == nullptr) return nullptr;
        return node->representative->head;
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