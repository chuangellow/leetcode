#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* newNode(int data);
void freeList(struct ListNode* head);
struct ListNode* insertToTail(struct ListNode* head, int data);
void traverse(struct ListNode* head);