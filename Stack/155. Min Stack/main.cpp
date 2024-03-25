#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct StackNode {
    int val;
    int minValue;
    StackNode *next;
    StackNode(int val, int minValue): val(val), minValue(minValue), next(nullptr) {}
};

class MinStack {
private:
    StackNode *pseudoHead;
    int size;
public:
    MinStack(): size(0) {
        pseudoHead = new StackNode(-1, INT32_MAX);
    }

    bool isEmpty() {
        return (size <= 0);
    }
    
    void push(int val) {
        StackNode *newNode = new StackNode(val, (val < pseudoHead->minValue)? val: pseudoHead->minValue);
        pseudoHead->minValue = (val < pseudoHead->minValue)? val: pseudoHead->minValue;
        newNode->next = pseudoHead->next;
        pseudoHead->next = newNode;
        size++;
    }
    
    void pop() {
        if (isEmpty()) return;
        StackNode *temp = pseudoHead->next;
        pseudoHead->next = temp->next;
        size--;
        if (!isEmpty()) {
            pseudoHead->minValue = pseudoHead->next->minValue;
        }
        else {
            pseudoHead->minValue = INT32_MAX;
        }
        delete temp;
    }
    
    int top() {
        return pseudoHead->next->val;
    }
    
    int getMin() {
        return pseudoHead->minValue;
    }

    void traverse() {
        StackNode *currentNode = pseudoHead->next;
        while (currentNode != nullptr) {
            cout << currentNode->val << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
};

int main(void) {
    int numCommands;
    cin >> numCommands;
    MinStack *minStack;
    for (int i = 0; i < numCommands; i++) {
        string command;
        cin >> command;
        cout << command << endl;
        if (command.compare("MinStack") == 0) {
            minStack = new MinStack();
        }
        else if (command.compare("push") == 0) {
            int val;
            cin >> val;
            minStack->push(val);
        }
        else if (command.compare("pop") == 0) {
            minStack->pop();
        }
        else if (command.compare("top") == 0) {
            cout << minStack->top() << endl;
        }
        else if (command.compare("getMin") == 0) {
            cout << minStack->getMin() << endl;
        }
        else {
            cout << "Invalid command!!!" << endl;
        }
        minStack->traverse();
    }
}