#include <iostream>
#include <vector>
#include <unordered_map>

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

void traverse(ListNode *head) {
    ListNode *currentNode = head;
    while (currentNode != nullptr) {
        cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
    return;
}

class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *pseudoHead = new ListNode();
        pseudoHead->next = head;
        ListNode *currentNode = pseudoHead->next;
        unordered_map<int, int> table;
        while (currentNode != nullptr) {
            table[currentNode->val]++;
            currentNode = currentNode->next;
        }
        ListNode *prevNode = pseudoHead;
        while (prevNode != nullptr && prevNode->next != nullptr) {
            while (prevNode->next != nullptr && table[prevNode->next->val] > 1) {
                prevNode->next = prevNode->next->next;
            }
            prevNode = prevNode->next;
        }
        return pseudoHead->next;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    ListNode *head = createList(nums);
    traverse(head);
    Solution sol;
    head = sol.deleteDuplicatesUnsorted(head);
    traverse(head);
    return 0;
}