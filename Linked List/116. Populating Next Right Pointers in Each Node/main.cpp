#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    void inorderTraverse(Node* root) {
        if (root == nullptr) return;
        inorderTraverse(root->left);
        cout << root->val << " ";
        inorderTraverse(root->right);
    }
    Node* createTree(vector<int>& nums, int n) {
        Node* root = new Node(nums[0]);
        vector<Node*> nodes = {root};
        for (int i = 1; i < n; i++) {
            Node* newNode = new Node(nums[i]);
            int parentIdx = (i - 1) / 2;
            Node* parent = nodes[parentIdx];
            if (parentIdx * 2 + 1 == i) parent->left = newNode;
            else parent->right = newNode;
            nodes.push_back(newNode);
        }
        return root;
    }
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        int level = 1;
        int numNodes = 1;
        Node* prevNode = nullptr;
        while (!(q.empty())) {
            Node* currentNode = q.front();
            q.pop();
            if (currentNode == nullptr) continue;
            if (numNodes == (1 << (level - 1))) {
                level += 1;
            }
            else if (numNodes == (1 << level)) {
                prevNode->next = nullptr;
            }
            else if (prevNode != nullptr) {
                prevNode->next = currentNode;
            }
            if (currentNode->left != nullptr) q.push(currentNode->left);
            if (currentNode->right != nullptr) q.push(currentNode->right);
            numNodes += 1;
            prevNode = currentNode;
        }
        return root;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    Node* root = sol.createTree(nums, n);
    sol.inorderTraverse(root);
    return 0;
}