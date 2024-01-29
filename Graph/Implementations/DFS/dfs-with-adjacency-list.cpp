#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <queue>

enum {WHITE, GRAY, BLACK};
enum {NO, TREE, BACK, FORWARD, CROSS};

using namespace std;

class Vertex {
public:
    int index;
    int color;
    int discoveryTime;
    int finishingTime;
    shared_ptr<Vertex> predecesor;
    Vertex(int index): index(index), color(WHITE), discoveryTime(INT32_MAX), finishingTime(INT32_MAX), predecesor(nullptr) {}
};

class EdgeNode {
public:
    int index;
    shared_ptr<EdgeNode> next;
    int edgeClass;
    EdgeNode(int index): index(index), next(nullptr), edgeClass(TREE) {}
};

class LinkedList {
public:
    shared_ptr<EdgeNode> head;
    shared_ptr<EdgeNode> tail;
    int len;
    LinkedList(): tail(nullptr), len(0) {
        shared_ptr<EdgeNode> pseudoHead = make_shared<EdgeNode>(-1);
        this->head = pseudoHead;
    }
    LinkedList(shared_ptr<EdgeNode> node): tail(node), len(1) {
        shared_ptr<EdgeNode> pseudoHead = make_shared<EdgeNode>(-1);
        this->head = pseudoHead;
    }
    void insertToTail(int index) {
        if (head == nullptr || tail == nullptr) {
            shared_ptr<EdgeNode> newVertex = make_shared<EdgeNode>(index);
            shared_ptr<EdgeNode> pseudoHead = make_shared<EdgeNode>(-1);
            pseudoHead->next = newVertex;
            head = pseudoHead;
            tail = newVertex;
            len = 1;
            return;
        }
        shared_ptr<EdgeNode> newVertex = make_shared<EdgeNode>(index);
        tail->next = newVertex;
        tail = newVertex;
        len += 1;
        return;
    }
    void traverse() {
        if (head == nullptr || tail == nullptr) return;
        shared_ptr<EdgeNode> currentVertex = head->next;
        while (currentVertex != nullptr) {
            cout << currentVertex->index << " ";
            currentVertex = currentVertex->next;
        }
        cout << endl;
        return;
    }
};

class Graph {
public:
    int numNodes;
    vector<shared_ptr<Vertex>> vertices;
    vector<shared_ptr<LinkedList>> adjacencyList;
    Graph(vector<vector<int>>& adjacencyMatrix): numNodes(adjacencyMatrix.size()) {
        for (int i = 0; i < numNodes; i++) {
            shared_ptr<LinkedList> list = make_shared<LinkedList>();
            for (int j = 0; j < numNodes; j++) {
                if (adjacencyMatrix[i][j]) {
                    list->insertToTail(j);
                }
            }
            adjacencyList.push_back(list);
        }
        for (int i = 0; i < numNodes; i++) {
            shared_ptr<Vertex> vertex = make_shared<Vertex>(i);
            vertices.push_back(vertex);
        }
    }
    void showTimeStamp() {
        for (int i = 0; i < numNodes; i++) {
            cout << vertices[i]->discoveryTime << " " << vertices[i]->finishingTime << endl;
        }
        cout << endl;
    }
    void showEdges() {
        unordered_map<int, string> edgeClassMap = {{NO, "NO"}, {TREE, "TREE"}, {BACK, "BACK"}, {FORWARD, "FORWARD"}, {CROSS, "CROSS"}};
        for (int i = 0; i < numNodes; i++) {
            shared_ptr<EdgeNode> edge = adjacencyList[i]->head->next;
            while (edge != nullptr) {
                cout << "(" << i << "," << edge->index << "): " << edgeClassMap[edge->edgeClass] << endl;
                edge = edge->next;
            }
        }
    }
};

void DFSVisit(int sourceIdx, int* timeStamp, shared_ptr<Graph> graph) {
    *timeStamp = *timeStamp + 1;
    shared_ptr<Vertex> sourceVertex = graph->vertices[sourceIdx];
    sourceVertex->discoveryTime = *timeStamp;
    sourceVertex->color = GRAY;
    shared_ptr<EdgeNode> neighborEdgeNode = graph->adjacencyList[sourceIdx]->head->next; 
    while (neighborEdgeNode != nullptr) {
        if (neighborEdgeNode->index == sourceIdx) {
            neighborEdgeNode->edgeClass = BACK;
            neighborEdgeNode = neighborEdgeNode->next;
            continue;
        }
        shared_ptr<Vertex> neighborVertex = graph->vertices[neighborEdgeNode->index];
        if (neighborVertex->color == WHITE) {
            neighborVertex->predecesor = sourceVertex;
            neighborEdgeNode->edgeClass = TREE;
            DFSVisit(neighborEdgeNode->index, timeStamp, graph);
        }
        else if (neighborVertex->color == GRAY) {
            neighborEdgeNode->edgeClass = BACK;
        }
        else {
            neighborEdgeNode->edgeClass = (neighborVertex->discoveryTime > sourceVertex->discoveryTime)? FORWARD: CROSS;
        }
        neighborEdgeNode = neighborEdgeNode->next;
    }
    *timeStamp = *timeStamp + 1;
    sourceVertex->finishingTime = *timeStamp;
    sourceVertex->color = BLACK;
}

void DFS(shared_ptr<Graph> graph) {
    int timeStamp = 0;
    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->vertices[i]->color == WHITE) {
            DFSVisit(i, &timeStamp, graph);
        }
    }
    return;
}

int main(void) {
    int numNodes;
    cin >> numNodes;
    vector<vector<int>> adjacencyMatrix(numNodes, vector<int>(numNodes));
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }
    shared_ptr<Graph> graph = make_shared<Graph>(adjacencyMatrix);
    DFS(graph);
    graph->showTimeStamp();
    graph->showEdges();
}