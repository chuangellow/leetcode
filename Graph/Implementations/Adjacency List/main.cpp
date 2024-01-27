#include <iostream>
#include <vector>
#include <memory>

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
    Graph(int numNodes, vector<vector<int>>& edges) {
        lists.resize(numNodes);
        for (auto edge: edges) {
            lists[edge[0]]->insertToTail(edge[1]);
        }
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }
    shared_ptr<Graph> graph = make_shared<Graph>(adjacencyMatrix);
    for (int i = 0; i < n; i++) {
        graph->lists[i]->traverse();
    }
    return 0;
}