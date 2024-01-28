#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    shared_ptr<Node> next;
    Node(int data, shared_ptr<Node> next): data(data), next(next) {}
};

class LinkedList {
public:
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    int len;
    LinkedList(): tail(nullptr), len(0) {
        shared_ptr<Node> pseudoHead = make_shared<Node>(-1, nullptr);
        this->head = pseudoHead;
    }
    LinkedList(shared_ptr<Node> node): tail(node), len(1) {
        shared_ptr<Node> pseudoHead = make_shared<Node>(-1, node);
        this->head = pseudoHead;
    }
    void insertToTail(int data) {
        if (head == nullptr || tail == nullptr) {
            shared_ptr<Node> newNode = make_shared<Node>(data, nullptr);
            shared_ptr<Node> pseudoHead = make_shared<Node>(-1, newNode);
            head = pseudoHead;
            tail = newNode;
            len = 1;
            return;
        }
        shared_ptr<Node> newNode = make_shared<Node>(data, nullptr);
        tail->next = newNode;
        tail = newNode;
        len += 1;
        return;
    }
    void traverse() {
        if (head == nullptr || tail == nullptr) return;
        shared_ptr<Node> currentNode = head->next;
        while (currentNode != nullptr) {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
        return;
    }
    bool findData(int data) {
        if (head == nullptr || tail == nullptr) return false;
        shared_ptr<Node> currentNode = head->next;
        while (currentNode != nullptr) {
            if (currentNode->data == data) return true;
            currentNode = currentNode->next;
        }
        return false;
    }
};

class Graph {
public:
    vector<shared_ptr<LinkedList>> lists;
    Graph(vector<vector<int>>& adjacencyMatrix) {
        int n = adjacencyMatrix.size();
        for (int i = 0; i < n; i++) {
            shared_ptr<LinkedList> list = make_shared<LinkedList>();
            for (int j = 0; j < n; j++) {
                if (adjacencyMatrix[i][j]) list->insertToTail(j);
            }
            lists.push_back(list);
        }
    }
    Graph(int numNodes, vector<vector<int>>& edges, bool isDirected) {
        for (int i = 0; i < numNodes; i++) {
            shared_ptr<LinkedList> list = make_shared<LinkedList>();
            lists.push_back(list);
        }
        for (auto edge: edges) {
            lists[edge[0]]->insertToTail(edge[1]);
            if (!(isDirected)) lists[edge[1]]->insertToTail(edge[0]);
        }
    }
};

class Solution {
public:
    void DFSVisit(int sourceIdx, shared_ptr<Graph> graph, int n, vector<bool>& visited) {
        shared_ptr<LinkedList> edges = graph->lists[sourceIdx];
        shared_ptr<Node> currentEdge = edges->head->next;
        visited[sourceIdx] = true;
        while (currentEdge != nullptr) {
            int nextIdx = currentEdge->data;
            if (nextIdx == sourceIdx) {
                currentEdge = currentEdge->next;
                continue;
            }
            if (!visited[nextIdx]) {
                DFSVisit(nextIdx, graph, n, visited);
            }
            currentEdge = currentEdge->next;
        }
        return;
    }
    bool DFS(shared_ptr<Graph> graph, int n) {
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFSVisit(i, graph, n, visited);
                count++;
            }
        }
        return (count == 1)? true: false;
    }
    bool checkConnected(int n, vector<vector<int>>& edges) {
        shared_ptr<Graph> graph = make_shared<Graph>(n, edges, false);
        return DFS(graph, n);
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        return ((m == n - 1) && checkConnected(n, edges));
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