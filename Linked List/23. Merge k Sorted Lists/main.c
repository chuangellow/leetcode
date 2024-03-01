#include <stdio.h>
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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* newList = (struct ListNode*) malloc(sizeof(struct ListNode));
    return newList;
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