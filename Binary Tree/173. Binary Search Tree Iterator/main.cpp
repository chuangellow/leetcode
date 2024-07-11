#include <iostream>
#include <vector>
#include <string>
#include <queue>

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
    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
        n++;
    }
public:
    int currentIdx = 0;
    int n = 0;
    vector<int> inorder;
    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
    }
    
    int next() {
        int result = inorder[currentIdx];
        currentIdx++;
        return result;
    }
    
    bool hasNext() {
        return (currentIdx < n);
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