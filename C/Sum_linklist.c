// Description: You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// Example:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8] (342 + 465 = 807)

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = createNode(0);
    struct ListNode* current = dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        
        current->next = createNode(sum % 10);
        current = current->next;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    if (carry > 0) {
        current->next = createNode(carry);
    }
    return dummyHead->next;
}

void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d", node->val);
        if (node->next != NULL) {
            printf(" -> ");
        }
        node = node->next;
    }
    printf("\n");
}

int main() {
    //  2 -> 4 -> 3
    struct ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    //  5 -> 6 -> 4
    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    struct ListNode* result = addTwoNumbers(l1, l2);

    printList(result); // 7 -> 0 -> 8

    return 0;
}
