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
    ListNode* mergeLists(ListNode* first, ListNode* second) {
        if (first == nullptr) return second;
        if (second == nullptr) return first;
        ListNode* pseudoHead = new ListNode(-1), *current = pseudoHead;
        while (first != nullptr && second != nullptr) {
            if (first->val <= second->val) {
                current->next = first;
                first = first->next;
            }
            else {
                current->next = second;
                second = second->next;
            }
            current = current->next;
        }
        while (first != nullptr) {
            current->next = first;
            current = current->next;
            first = first->next;
        }
        while (second != nullptr) {
            current->next = second;
            current = current->next;
            second = second->next;
        }
        return pseudoHead->next;
    }
    void traverse(ListNode* head) {
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *firstHead = head, *secondHead = head, *fast = secondHead;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next;
            if (fast->next == nullptr) break;
            fast = fast->next;
            if (fast->next == nullptr) break;
            secondHead = secondHead->next;
        }
        ListNode* temp = secondHead->next;
        secondHead->next = nullptr;
        secondHead = temp;
        head = this->sortList(head);
        secondHead = this->sortList(secondHead);
        ListNode *mergeHead = this->mergeLists(head, secondHead);
        return mergeHead;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    ListNode *head = createList(nums);
    Solution sol;
    sol.traverse(head);
    sol.sortList(head);
    sol.traverse(head);
}