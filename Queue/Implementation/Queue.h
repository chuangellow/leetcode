#include <vector>

struct QueueNode {
    int data;
    std::shared_ptr<QueueNode> next;
    QueueNode();
    QueueNode(int data);
};

class Queue {
private:
    std::shared_ptr<QueueNode> pseudoHead;
    int len;
public:
    Queue();
    void enqueue(int data);
    int dequeue();
    int getFront();
    void printQueue();
    int getLen();
    bool isEmpty();
};