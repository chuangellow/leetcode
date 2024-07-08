#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node *prev, *next;
    Node(): val(-1), prev(this), next(this) {};
    Node(int x): val(x), prev(this), next(this) {};
};

struct List {
    Node *head;
    int n;
    List(): n(0), head(nullptr) {};
    void insertToTail(int x) {
        Node *newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
            n++;
            return;
        }
        Node *tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        n++;
    }
    void createPeople(int n) {
        for (int i = 1; i <= n; i++) {
            insertToTail(i);
        }
    }
    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        n--;
        delete node;
    }
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1 || k == 1) return n;
        int currentCount = 1;
        List *people = new List();
        people->createPeople(n);
        Node *currentNode = people->head;
        while (people->n > 1) {
            currentNode = currentNode->next;
            currentCount += 1;
            if (currentCount == k) {
                Node *nextNode = currentNode->next;
                people->removeNode(currentNode);
                currentNode = nextNode;
                currentCount = 1;
            }
        }
        return currentNode->val;
   }
};

int main(void) {
    int n, k;
    cin >> n >> k;
    Solution sol;
    cout << sol.findTheWinner(n, k) << endl;
}