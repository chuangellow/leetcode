#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

ListNode* insertAfterNode(ListNode *node, int num) {
    ListNode *newNode = new ListNode(num);
    node->next = newNode;
    return newNode;
} 

ListNode* createList(vector<int>& nums) {
    int n = nums.size();
    ListNode* head = new ListNode(nums[0]);
    ListNode* currentNode = head;
    for (int i = 1; i < n; i++) {
        currentNode = insertAfterNode(currentNode, nums[i]);
    }
    return head;
}

class Solution {
public:
    int getListLength(ListNode *head) {
        int len = 0;
        ListNode *currentNode = head;
        while (currentNode != nullptr) {
            len++;
            currentNode = currentNode->next;
        }
        return len;
    }
    bool checkCritical(ListNode *prev, ListNode *current) {
        if (prev == nullptr || current == nullptr) return false;
        if (current->val < prev->val && current->val < current->next->val) return true;
        if (current->val > prev->val && current->val > current->next->val) return true;
        return false;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int n = getListLength(head);
        vector<int> result = {-1, -1};
        if (n <= 3) return result;
        ListNode *prev = nullptr, *current = head;
        vector<int> criticalIdx;
        int idx = 1;
        while (current->next != nullptr) {
            if (checkCritical(prev, current)) {
                criticalIdx.push_back(idx);
            }
            idx++;
            prev = current;
            current = current->next;
        }
        if (criticalIdx.size() < 2) return result;
        result[1] = criticalIdx.back() - criticalIdx.front();
        int minDiff = INT32_MAX;
        for (int i = 0; i < criticalIdx.size() - 1; i++) {
            minDiff = min(minDiff, criticalIdx[i+1] - criticalIdx[i]);
        }
        result[0] = minDiff;
        return result;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    ListNode *head = createList(nums);
    Solution sol;
    vector<int> result = sol.nodesBetweenCriticalPoints(head);
    for (auto num: result) {
        cout << num << " ";
    }
    return 0;
}