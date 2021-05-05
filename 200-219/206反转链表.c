#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

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
void createList(int* arr, int n, struct ListNode* head) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode*));

    temp = head;
    for (int i = 0; i < n; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode*));
        node->val             = arr[i];
        temp->next            = node;
        temp                  = node;
    }
    temp->next = NULL;
}

/**
 * 方法一：双指针
 * curr: 当前指针
 * next: 下个指针，保存当前指针的下一个指针
 * prev: 前置指针，保存当前指针的前一个指针
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    struct ListNode* prev = NULL;

    while (curr) {
        next       = curr->next;
        curr->next = prev;
        prev       = curr;
        curr       = next;
    }

    return prev;
}

/**
 * 方法二：递归法
    reverseList: head=1
        reverseList: head=2
            reverseList: head=3
                reverseList: head=4
                    reverseList: head=5 
					终止返回 newHead=5
                    cur=4: 4.next.next->4，即5->4
			    cur=3: 3.next.next->3，即4->3
		    cur=2: 2.next.next->2，即3->2
	    cur=1: 1.next.next->1，即2->1
	最后返回cur
 */
// struct ListNode* reverseList(struct ListNode* head) {
//     if (head == NULL || head->next == NULL) {
//         return head;
//     }
//     struct ListNode* newHead = reverseList(head->next);
//     head->next->next         = head;
//     head->next               = NULL;
//     return newHead;
// }

int main() {
    int              arr[] = {1, 2, 3, 4, 5};
    int              n     = sizeof(arr) / sizeof(arr[0]);
    struct ListNode* head  = (struct ListNode*)malloc(sizeof(struct ListNode*));

    createList(arr, n, head);
    displayList(head->next);

    struct ListNode* ret = reverseList(head->next);
    displayList(ret);

    return 0;
}