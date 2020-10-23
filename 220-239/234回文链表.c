#include <malloc.h>
#include <stdio.h>

typedef enum {
    false = 0,
    true  = 1
} bool;

struct ListNode {
    int              val;
    struct ListNode* next;
};

void displayList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

/**
 * 创建单向链表
 * 存储的第一个值在 head->next 中
 */
void createList(int arr[], int n, struct ListNode* head) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode*));

    temp = head;
    for (int i = 0; i < n; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode*));
        node->val             = arr[i];
        node->next            = NULL;
        temp->next            = node;
        temp                  = node;
    }
}

/**
 * 方法一：数组存储
 *  - 用数组把链表数值存储
 *  - 然后循环遍历数组比较
 */
bool isPalindrome(struct ListNode* head) {
    int node[50001];
    int index = 0;
    while (head != NULL) {
        node[index++] = head->val;
        head          = head->next;
    }
    for (int i = 0, j = index - 1; i < j; i++, j--) {
        if (node[i] != node[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    int              arr[] = {1, 2, 2, 1};
    int              n     = sizeof(arr) / sizeof(arr[0]);
    struct ListNode* head  = (struct ListNode*)malloc(sizeof(struct ListNode*));

    createList(arr, n, head);
    displayList(head->next);

    if (isPalindrome(head->next)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}