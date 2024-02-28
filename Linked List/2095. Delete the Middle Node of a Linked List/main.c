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

struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head == NULL) return head;
    struct ListNode* slowNode = head;
    struct ListNode* fastNode = head->next;
    if (fastNode == NULL) {
        return NULL;
    }
    if (fastNode->next == NULL) {
        slowNode->next = NULL;
        return head;
    }
    while (fastNode->next != NULL && fastNode->next->next != NULL) {
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;
    }
    slowNode->next = slowNode->next->next;
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
    list->head = deleteMiddle(list->head);
    list->len--;
    traverse(list);
    free(nums);
    freeList(list);
}