#include <iostream>
#include <vector>
#include <memory>
#include <queue>

enum {WHITE, GRAY, BLACK};

using namespace std;

class Vertex {
public:
    int color;
    int distance;
    shared_ptr<Vertex> predecesor;
    Vertex(): color(WHITE), distance(INT32_MAX), predecesor(nullptr) {}
};

class Graph {
public:
    int numNodes;
    vector<shared_ptr<Vertex>> vertices;
    vector<vector<int>> adjacencyMatrix;
    Graph(vector<shared_ptr<Vertex>> vertices, vector<vector<int>>& adjacencyMatrix)
        : numNodes(vertices.size()), vertices(vertices), adjacencyMatrix(adjacencyMatrix) {}
};

void BFS(int sourceIdx, shared_ptr<Graph> graph) {
    vector<shared_ptr<Vertex>> vertices = graph->vertices;
    vertices[sourceIdx]->color = GRAY;
    vertices[sourceIdx]->distance = 0;
    queue<int> q;
    q.push(sourceIdx);
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (int j = 0; j < graph->numNodes; j++) {
            if (i == j) continue;
            if (graph->adjacencyMatrix[i][j] != 0) {
                if (vertices[j]->color == WHITE) {
                    vertices[j]->color = GRAY;
                    vertices[j]->distance = vertices[i]->distance + 1;
                    vertices[j]->predecesor = vertices[i];
                    q.push(j);
                }
            }
        }
        vertices[i]->color = BLACK;
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
    vector<shared_ptr<Vertex>> vertices;
    for (int i = 0; i < numNodes; i++) {
        shared_ptr<Vertex> vertex = make_shared<Vertex>();
        vertices.push_back(vertex);
    }
    shared_ptr<Graph> graph = make_shared<Graph>(vertices, adjacencyMatrix);
    BFS(0, graph);
}