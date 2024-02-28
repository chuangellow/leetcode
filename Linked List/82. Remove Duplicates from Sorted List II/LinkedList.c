#include "LinkedList.h"

struct ListNode* newNode(int data) {
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

void freeList(struct ListNode* head) {
    if (head == NULL) return;
    struct ListNode* currentNode = head;
    while (currentNode != NULL) {
        struct ListNode* temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
    return;
}

struct ListNode* insertToTail(struct ListNode* head, int data) {
    struct ListNode* node = newNode(data);
    if (head == NULL) {
        return node;
    }
    struct ListNode* currentNode = head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = node;
    return head;
}

void traverse(struct ListNode* head) {
    if (head == NULL) return;
    struct ListNode* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->val);
        currentNode = currentNode->next;
    }
    printf("\n");
}