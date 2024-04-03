#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void traverse(ListNode* head) {
        ListNode* currentNode = head;
        while (currentNode != nullptr) {
            cout << currentNode->val << " ";
        }
        cout << endl;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
    }
};

ListNode* createList(vector<int>& nums, int n) {
    ListNode* head;
    head->val = nums[0];
    ListNode* currentNode = head;
    for (int i = 1; i < n; i++) {
        ListNode* newNode;
        newNode->val = nums[i];
        currentNode->next = newNode;
        currentNode = newNode;
    }
    currentNode->next = nullptr;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    ListNode* head = createList(nums, n);
    Solution sol;
    sol.traverse(head);
    int left, right;
    cin >> left >> right;
    ListNode* reverseList = sol.reverseBetween(head, left, right);
    sol.traverse(reverseList);
}