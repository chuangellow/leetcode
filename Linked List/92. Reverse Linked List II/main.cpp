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
            currentNode = currentNode->next;
        }
        cout << endl;
        return;
    }
    void reverse(ListNode* leftNode, ListNode* rightNode) {
        ListNode* prev = nullptr, *current = leftNode;
        while (current != rightNode) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        current->next = prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* pseudoHead = new ListNode(-1, head);
        ListNode* prevNode, *leftNode, *rightNode, *nextNode;
        prevNode = pseudoHead;
        int index = 1;
        while (prevNode != nullptr) {
            if (index == left) break;
            index++;
            prevNode = prevNode->next;
        }
        leftNode = prevNode->next;
        rightNode = prevNode->next;
        while (rightNode != nullptr) {
            if (index == right) break;
            index++;
            rightNode = rightNode->next;
        }
        nextNode = rightNode->next;
        reverse(leftNode, rightNode);
        prevNode->next = rightNode;
        leftNode->next = nextNode;
        return pseudoHead->next;
    }
};

ListNode* createList(vector<int>& nums, int n) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* currentNode = head;
    for (int i = 1; i < n; i++) {
        ListNode* newNode = new ListNode(nums[i]);
        currentNode->next = newNode;
        currentNode = newNode;
    }
    currentNode->next = nullptr;
    return head;
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