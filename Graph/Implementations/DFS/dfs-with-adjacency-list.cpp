#include <iostream>
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

class Graph {
public:
    int numNodes;
    vector<shared_ptr<Vertex>> vertices;
    vector<vector<int>> adjacencyMatrix;
    Graph(vector<shared_ptr<Vertex>> vertices, vector<vector<int>>& adjacencyMatrix)
        : numNodes(vertices.size()), vertices(vertices), adjacencyMatrix(adjacencyMatrix) {}
    void showTimeStamp() {
        for (int i = 0; i < numNodes; i++) {
            cout << vertices[i]->discoveryTime << " " << vertices[i]->finishingTime << endl;
        }
        return;
    }
    void showEdges() {
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
};

void DFSVisit(int sourceIdx, int* timeStamp, shared_ptr<Graph> graph) {
    *timeStamp = *timeStamp + 1;
    vector<shared_ptr<Vertex>> vertices = graph->vertices;
    vertices[sourceIdx]->color = GRAY;
    vertices[sourceIdx]->discoveryTime = *timeStamp;
    for (int j = 0; j < graph->numNodes; j++) {
        if (sourceIdx == j) {
            if (graph->adjacencyMatrix[sourceIdx][j] != NO) graph->adjacencyMatrix[sourceIdx][j] = BACK;
            continue;
        }
        if (graph->adjacencyMatrix[sourceIdx][j] != NO) {
            if (vertices[j]->color == WHITE) {
                graph->adjacencyMatrix[sourceIdx][j] = TREE;
                vertices[j]->predecesor = vertices[sourceIdx];
                DFSVisit(j, timeStamp, graph);
            }
            else if (vertices[j]->color == GRAY) {
                graph->adjacencyMatrix[sourceIdx][j] = BACK;
            }
            else if (vertices[j]->color == BLACK) {
                if (vertices[j]->discoveryTime > vertices[sourceIdx]->discoveryTime) {
                    graph->adjacencyMatrix[sourceIdx][j] = FORWARD;
                }
                else {
                    graph->adjacencyMatrix[sourceIdx][j] = CROSS;
                }
            }
        }
    }
    vertices[sourceIdx]->color = BLACK;
    *timeStamp = *timeStamp + 1;
    vertices[sourceIdx]->finishingTime = *timeStamp;
    return;
}

void DFS(shared_ptr<Graph> graph) {
    int timeStamp = 0;
    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->vertices[i]->color == WHITE) {
            DFSVisit(i, &timeStamp, graph);
        }
    }
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
    vector<shared_ptr<Vertex>> vertices;
    for (int i = 0; i < numNodes; i++) {
        shared_ptr<Vertex> vertex = make_shared<Vertex>(i);
        vertices.push_back(vertex);
    }
    shared_ptr<Graph> graph = make_shared<Graph>(vertices, adjacencyMatrix);
    DFS(graph);
    cout << "Time Stamp: " << endl;
    graph->showTimeStamp();
    cout << "Edges: " << endl;
    graph->showEdges();
}