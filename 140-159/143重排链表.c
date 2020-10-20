#include <malloc.h>
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
 * 方法一：指针数组存储
 *  - 先遍历，用指针数组存储
 *  - 再按照规律指向下一个地址
 */
// void reorderList(struct ListNode* head) {
//     if (head == NULL) {
//         return;
//     }

//     struct ListNode* vec[40001];
//     struct ListNode* temp = head;
//     int              n    = 0;
//     while (temp != NULL) {
//         vec[n++] = temp;
//         temp     = temp->next;
//     }

//     int i = 0, j = n - 1;
//     while (i < j) {
//         vec[i]->next = vec[j];
//         i++;
//         if (i == j) {
//             break;
//         }
//         vec[j]->next = vec[i];
//         j--;
//     }
//     vec[i]->next = NULL;
//     head         = vec[0];
// }

/**
 * 方法二：二分链表，依次连接
 *  - 找到原链表的中点，分割成两个链表
 *  - 将后面链表逆序
 *  - 两个链表依次连接
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next                = prev;
        prev                      = curr;
        curr                      = nextTemp;
    }
    return prev;
}
void mergeList(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l1_temp;
    struct ListNode* l2_temp;
    while (l1 != NULL && l2 != NULL) {
        l1_temp = l1->next;
        l2_temp = l2->next;

        l1->next = l2;
        l1       = l1_temp;
        l2->next = l1;
        l2       = l2_temp;
    }
}

void reorderList(struct ListNode* head) {
    if (head == NULL) {
        return;
    }

    struct ListNode* mid = middleNode(head);
    struct ListNode* l1  = head;
    struct ListNode* l2  = reverseList(mid->next);
    mid->next            = NULL;
    mergeList(l1, l2);
}

int main() {
    int              arr[] = {1, 2, 3, 4, 5, 6};
    int              n     = sizeof(arr) / sizeof(arr[0]);
    struct ListNode* head  = (struct ListNode*)malloc(sizeof(struct ListNode*));

    createList(arr, n, head);
    displayList(head->next);
    reorderList(head->next);
    displayList(head->next);

    return 0;
}