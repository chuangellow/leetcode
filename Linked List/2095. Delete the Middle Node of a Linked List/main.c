#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

typedef struct LinkedList {
    ListNode* head;
    int len;
} LinkedList;

ListNode* newNode(int data) {
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    return node;
}

LinkedList* newList() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->len = 0;
    return list;
}

void insertToTail(LinkedList* list, int data) {
    ListNode* node = newNode(data);
    ListNode* currentNode = list->head;
    if (currentNode == NULL) {
        list->head = node;
        list->len++;
        return;
    }
    else {
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = node;
        list->len++;
    }
}

void freeList(LinkedList* list) {
    ListNode* currentNode = list->head;
    while (currentNode != NULL) {
        ListNode* tempNode = currentNode;
        currentNode = currentNode->next;
        free(tempNode);
    }
    free(list);
    return;
}

void traverse(LinkedList* list) {
    ListNode* currentNode = list->head;
    printf("Len: %d\n", list->len);
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int getLen(struct ListNode* head) {
    int len = 0;
    for (struct ListNode* currentNode = head; currentNode != NULL; currentNode = currentNode->next) len++;
    return len;
}

struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head == NULL) return head;
    int len = getLen(head);
    if (len == 1) return NULL;
    if (len == 2) {
        head->next = NULL;
        return head;
    }
    int mid = len >> 1;
    int currentIdx = 0;
    struct ListNode* currentNode = head;
    while (currentIdx != mid - 1) {
        currentNode = currentNode->next;
        currentIdx++;
    }
    currentNode->next = currentNode->next->next;
    return head;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int* nums = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    LinkedList* list = newList();
    for (int i = 0; i < n; i++) {
        insertToTail(list, nums[i]);
    }
    traverse(list);
    free(nums);
    freeList(list);
}