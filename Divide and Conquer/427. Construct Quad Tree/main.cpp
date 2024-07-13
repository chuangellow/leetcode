#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* constructSubGrid(vector<vector<int>>& grid, pair<int, int> startPos, int subGridLen) {
        Node *root = new Node();
        if (subGridLen == 1) {
            root->val = grid[startPos.first][startPos.second];
            root->isLeaf = true;
            return root;
        }
        bool flag = true;
        int prev = grid[startPos.first][startPos.second];
        for (int i = startPos.first; i < startPos.first + subGridLen; i++) {
            for (int j = startPos.second; j < startPos.second + subGridLen; j++) {
                if (grid[i][j] != prev) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            root->val = prev;
            root->isLeaf = true;
            return root;
        }
        subGridLen = subGridLen / 2;
        root->val = 0;
        root->isLeaf = false;
        root->topLeft = constructSubGrid(grid, {startPos.first, startPos.second}, subGridLen);
        root->topRight = constructSubGrid(grid, {startPos.first, startPos.second+subGridLen}, subGridLen);
        root->bottomLeft = constructSubGrid(grid, {startPos.first+subGridLen, startPos.second}, subGridLen);
        root->bottomRight = constructSubGrid(grid, {startPos.first+subGridLen, startPos.second+subGridLen}, subGridLen);
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return constructSubGrid(grid, {0, 0}, n);
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    Solution sol;
    return 0;
}