#include <iostream>
#include <vector>
#include <memory>
#include <queue>

enum {WHITE, GRAY, BLACK};

using namespace std;

class Vertex {
public:
    int color;
    int discoveryTime;
    int finishingTime;
    shared_ptr<Vertex> predecesor;
    Vertex(): color(WHITE), discoveryTime(0), finishingTime(0), predecesor(nullptr) {}
};

class Graph {
public:
    int numNodes;
    vector<shared_ptr<Vertex>> vertices;
    vector<vector<int>> adjacencyMatrix;
    Graph(vector<shared_ptr<Vertex>> vertices, vector<vector<int>>& adjacencyMatrix)
        : numNodes(vertices.size()), vertices(vertices), adjacencyMatrix(adjacencyMatrix) {}
};

void DFSVisit(int sourceIdx, int* timeStamp, shared_ptr<Graph> graph) {
    *timeStamp = *timeStamp + 1;
    vector<shared_ptr<Vertex>> vertices = graph->vertices;
    vertices[sourceIdx]->color = GRAY;
    vertices[sourceIdx]->discoveryTime = *timeStamp;
    for (int j = 0; j < graph->numNodes; j++) {
        if (sourceIdx == j) continue;
        if (graph->adjacencyMatrix[sourceIdx][j] != 0) {
            if (vertices[j]->color == WHITE) {
                vertices[j]->predecesor = vertices[sourceIdx];
                DFSVisit(j, timeStamp, graph);
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
        shared_ptr<Vertex> vertex = make_shared<Vertex>();
        vertices.push_back(vertex);
    }
    shared_ptr<Graph> graph = make_shared<Graph>(vertices, adjacencyMatrix);
    DFS(graph);
    for (int i = 0; i < graph->numNodes; i++) {
        cout << graph->vertices[i]->discoveryTime << " " << graph->vertices[i]->finishingTime << endl;
    }
}