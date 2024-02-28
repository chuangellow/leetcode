#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "LinkedList.h"

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* slowHead = head;
    if (slowHead == NULL) return head;
    struct ListNode* fastHead = head->next;
    if (fastHead == NULL) return head;
    struct ListNode* pseudoHead = newNode(-1);
    pseudoHead->next = head;
    struct ListNode* prevHead = pseudoHead;
    while (fastHead) {
        if (slowHead->val != fastHead->val) {
            prevHead = prevHead->next;
            slowHead = slowHead->next;
            fastHead = fastHead->next;
        }
        else {
            while (fastHead && slowHead->val == fastHead->val) {
                struct ListNode* temp = fastHead;
                fastHead = fastHead->next;
                free(temp);
            }
            prevHead->next = fastHead;
            struct ListNode* temp = slowHead;
            slowHead = fastHead;
            if (fastHead != NULL) fastHead = fastHead->next;
            free(temp);
        }
    }
    return pseudoHead->next;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    struct ListNode* head = newNode(nums[0]);
    for (int i = 1; i < n; i++) {
        head = insertToTail(head, nums[i]);
    }
    traverse(head);
    head = deleteDuplicates(head);
    traverse(head);
    freeList(head);
    return 0;
}