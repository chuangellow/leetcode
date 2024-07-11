#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(vector<int>& nums) {
    int n = nums.size();
    TreeNode *root = new TreeNode(nums[0]);
    queue<TreeNode *> q;
    q.push(root);
    int currentIdx = 1;
    while (currentIdx < n) {
        TreeNode *parent = q.front();
        q.pop();
        TreeNode *left = new TreeNode(nums[currentIdx++]);
        parent->left = left;
        q.push(left);
        if (currentIdx >= n) break;
        TreeNode *right = new TreeNode(nums[currentIdx++]);
        parent->right = right;
        q.push(right);
    }
    return root;
}

void preorderTraversal(TreeNode *root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

class BSTIterator {
private:
    void _leftMostTraverse(TreeNode *root) {
        while (root != nullptr) {
            this->s.push(root);
            root = root->left;
        }
    }
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        _leftMostTraverse(root);
    }
    int next() {
        TreeNode* top = this->s.top();
        this->s.pop();
        if (top->right != nullptr) {
            _leftMostTraverse(top->right);
        }
        return top->val;
    }
    bool hasNext() {
        return !this->s.empty();
    }
};

int main(void) {
    int numNodes;
    vector<int> nums(numNodes);
    for (int i = 0; i < numNodes; i++) cin >> nums[i];
    TreeNode *root = buildTree(nums);
    BSTIterator* obj;
    int numCommands;
    cin >> numCommands;
    for (int i = 0; i < numCommands; i++) {
        string command;
        cin >> command;
        if (command == "BSTIterator") {
            obj = new BSTIterator(root);
        }
        else if (command == "next") {
            cout << obj->next() << endl;
        }
        else if (command == "hasNext") {
            cout << obj->hasNext() << endl;
        }
        else {
            cout << "Invalid Command!!!" << endl;
            continue;
        }
    }
}