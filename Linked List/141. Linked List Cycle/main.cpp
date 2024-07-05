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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *slow = head, *fast = head->next;
        while (slow != nullptr && fast != nullptr) {
            if (slow == fast) return true;
            slow = slow->next;
            if (fast->next == nullptr) return false;
            fast = fast->next->next;
        }
        return false;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    ListNode *head = createList(nums);
    Solution sol;
    cout << sol.hasCycle(head) << endl;
    return 0;
}