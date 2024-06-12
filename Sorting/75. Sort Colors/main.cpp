#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node () : data(-1), prev(this), next(this) {}
    Node (int data) : data(data), prev(this), next(this) {}
};

class LinkedList {
public:
    Node *head;
    Node *tail;
    LinkedList () {
        Node *node = new Node();
        head = tail = node;
    }
    void insertToTail(int data);
};

void LinkedList::insertToTail(int data) {
    Node *newNode = new Node(data);
    this->tail->next = newNode;
    newNode->prev = this->tail;
    newNode->next = this->head;
    this->tail = newNode;
}

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<LinkedList *> bucket(3);
        for (int i = 0; i < 3; i++) {
            bucket[i] = new LinkedList();
        }
        for (int i = 0; i < nums.size(); i++) {
            bucket[nums[i]]->insertToTail(nums[i]);
        }
        int index = 0;
        for (int i = 0; i < 3; i++) {
            Node *currentNode = bucket[i]->head->next;
            while (currentNode != bucket[i]->head) {
                nums[index] = i;
                index++;
                currentNode = currentNode->next;
            }
        }
        return;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    sol.sortColors(nums);
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;
}