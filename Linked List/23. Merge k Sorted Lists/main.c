#include <stdio.h>
#include <stdbool.h>
#include "LinkedList.h"

struct ListNode** createLists(int **nums, int *size, int listsSize) {
    struct ListNode** lists = (struct ListNode**)  malloc(sizeof(struct ListNode*) * listsSize);
    for (int i = 0; i < listsSize; i++) {
        struct ListNode* head = newNode(nums[i][0]);
        for (int j = 1; j < size[i]; j++) {
            insertToTail(head, nums[i][j]);
        }
        lists[i] = head;
    }
    return lists;
}

void freeLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0 || lists == NULL) return;
    for (int i = 0; i < listsSize; i++) {
        struct ListNode* currentNode = lists[i];
        while (currentNode != NULL) {
            struct ListNode* temp = currentNode;
            currentNode = currentNode->next;
            free(temp);
        }
    }
    free(lists);
}

void traverseLists(struct ListNode** lists, int listsSize) {
    if (lists == NULL || listsSize == 0) return;
    for (int i = 0; i < listsSize; i++) {
        traverse(lists[i]);
    }
    return;
}

bool insertMin(struct ListNode* dest, struct ListNode** lists, int listsSize) {
    int minVal = INT32_MAX;
    int minIdx = -1;
    for (int i = 0; i < listsSize; i++) {
        struct ListNode* node = lists[i];
        if (node == NULL) continue;
        if (node != NULL && node->val < minVal) {
            minVal = node->val;
            minIdx = i;
        }
    }
    if (minIdx == -1) return false;
    dest->next = lists[minIdx];
    lists[minIdx] = lists[minIdx]->next;
    dest = dest->next;
    return true;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0 || lists == NULL) return NULL;
    struct ListNode* newList = (struct ListNode*) malloc(sizeof(struct ListNode));
    newList->next = NULL;
    struct ListNode* currentNode = newList;
    while (insertMin(currentNode, lists, listsSize)) { currentNode = currentNode->next; }
    return newList->next;
}

int main(void) {
    int listsSize;
    scanf("%d", &listsSize);
    int **nums = (int **) malloc(sizeof(int *) * listsSize);
    int *size = (int *) malloc(sizeof(int) * listsSize);
    for (int i = 0; i < listsSize; i++) {
        int n;
        scanf("%d", &n);
        size[i] = n;
        int *num = (int *) malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &num[j]);
        }
        nums[i] = num;
    }
    struct ListNode** lists = createLists(nums, size, listsSize);
    traverseLists(lists, listsSize);
    struct ListNode* newList = mergeKLists(lists, listsSize);
    traverse(newList);
    for (int i = 0; i < listsSize; i++) {
        free(nums[i]);
    }
    free(nums);
    free(size);
    free(lists);
    free(newList);
    return 0;
}