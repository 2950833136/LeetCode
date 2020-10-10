#include <malloc.h>
#include <stdio.h>

typedef char bool;
#define false 0
#define true 1

struct ListNode {
    int              val;
    struct ListNode* next;
};

void displayList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

/**
 * 创建循环链表
 */
void createList(int arr[], int n, int pos, struct ListNode* head) {
    struct ListNode* temp1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* temp2 = (struct ListNode*)malloc(sizeof(struct ListNode*));

    temp1 = head;
    for (int i = 0; i < n; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode*));
        node->val             = arr[i];
        node->next            = NULL;
        temp1->next           = node;
        temp1                 = node;
    }

    if (pos >= 0) {
        temp2 = head;
        for (int j = 0; j <= pos; j++) {
            temp2 = temp2->next;
        }
        temp1->next = temp2;
    } else {
        temp1->next = NULL;
    }
}

/**
 * 提交函数
 * 双指针求解，快指针、慢指针
 *      如果存在循环必定会相遇，否则都会遍历到 NULL
 */
bool hasCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    int              arr[] = {3, 2, 0, -4};
    int              n     = sizeof(arr) / sizeof(arr[0]);
    int              pos   = 1;
    struct ListNode* head  = (struct ListNode*)malloc(sizeof(struct ListNode*));

    createList(arr, n, pos, head);
    // displayList(head->next);

    if (hasCycle(head)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}