#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

using namespace std;

class Solution {
public:
    void insertAfterNode(ListNode *node, int num) {
        ListNode *newNode = new ListNode(num);
        node->next = newNode;
        return;
    }
    void traverse(ListNode *head) {
        ListNode *currentNode = head;
        while (currentNode != nullptr) {
            cout << currentNode->val << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
    ListNode* mergeNodes(ListNode* head) {
        ListNode *prevNode = nullptr;
        ListNode *currentNode = head;
        ListNode *nextNode = head->next;
        int sum = 0;
        while (nextNode != nullptr) {
            if (nextNode->val == 0) {
                currentNode->val = sum;
                currentNode->next = nextNode;
                prevNode = currentNode;
                currentNode = nextNode;
                nextNode = currentNode->next;
                sum = 0;
            }
            else {
                sum += nextNode->val;
                nextNode = nextNode->next;
            }
        }
        prevNode->next = nullptr;
        return head;
   }
};

int main(void) {
    int numNodes;
    cin >> numNodes;
    vector<int> nums(numNodes);
    for (int i = 0; i < numNodes; i++) cin >> nums[i];
    ListNode *head = new ListNode(nums[0]);
    ListNode *currentNode = head;
    Solution sol;
    for (int i = 1; i < numNodes; i++) {
        sol.insertAfterNode(currentNode, nums[i]);
        currentNode = currentNode->next;
    }
    sol.traverse(head);
    return 0;
}