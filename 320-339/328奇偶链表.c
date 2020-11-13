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
 * 双指针
 *  - 更新奇数节点时，奇数节点的后一个节点需要指向偶数节点的后一个节点，因此令 odd.next = even.next，然后令 odd = odd.next，此时 odd 变成 even 的后一个节点。
 *  - 更新偶数节点时，偶数节点的后一个节点需要指向奇数节点的后一个节点，因此令 even.next = odd.next，然后令 even = even.next，此时 even 变成 odd 的后一个节点。
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    struct ListNode* evenHead = head->next;
    struct ListNode* odd      = head;
    struct ListNode* even     = evenHead;
    while (even != NULL && even->next != NULL) {
        odd->next  = even->next;
        odd        = odd->next;
        even->next = odd->next;
        even       = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main() {
    int              arr[] = {1, 2, 3, 4, 5, 6};
    int              n     = sizeof(arr) / sizeof(arr[0]);
    struct ListNode* head  = (struct ListNode*)malloc(sizeof(struct ListNode*));

    createList(arr, n, head);
    displayList(head->next);

    struct ListNode* ret = oddEvenList(head->next);
    displayList(head->next);

    return 0;
}