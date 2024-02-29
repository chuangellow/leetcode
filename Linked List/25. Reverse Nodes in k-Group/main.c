#include <stdio.h>
#include "LinkedList.h"

struct ListNode* reverse(struct ListNode* head, struct ListNode* tail, int len) {
    if (len == 1) return head;
    struct ListNode* prevNode = head;
    struct ListNode* currentNode = head->next;
    head->next = NULL;
    while (prevNode != tail) {
        struct ListNode* nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    return prevNode;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (k == 1) return head;
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* pseudoHead = newNode(0);
    pseudoHead->next = head;
    struct ListNode* prevNode = pseudoHead;
    struct ListNode* reverseHeadNode = head;
    struct ListNode* reverseTailNode = head->next;

    while (reverseTailNode != NULL) {
        int count = 2;
        while (reverseTailNode != NULL && count < k) {
            reverseTailNode  = reverseTailNode->next;
            count++;
        }
        if (reverseTailNode != NULL && count == k) {
            struct ListNode* nextNode = reverseTailNode->next;
            reverse(reverseHeadNode, reverseTailNode, k);
            prevNode->next = reverseTailNode;
            reverseHeadNode->next = nextNode;

            prevNode = reverseHeadNode;
            reverseHeadNode = (prevNode->next == NULL)? NULL: prevNode->next;
            reverseTailNode = (reverseHeadNode != NULL && reverseHeadNode->next != NULL)? reverseHeadNode->next: NULL;
        }
        else {
            struct ListNode* newHead = pseudoHead->next;
            free(pseudoHead);
            return newHead;
        }
    }
    struct ListNode* newHead = pseudoHead->next;
    free(pseudoHead);
    return newHead;
}

int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    struct ListNode* head = newNode(nums[0]);
    for (int i = 1; i < n; i++) {
        insertToTail(head, nums[i]);
    }
    traverse(head);
    struct ListNode* tail = head;
    int len = 1;
    while (tail->next != NULL) {
        len++;
        tail = tail->next;
    }
    head = reverseKGroup(head, k);
    traverse(head);
    freeList(head);
    return 0;
}