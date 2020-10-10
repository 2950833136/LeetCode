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
 * 双指针求解，快指针、慢指针
 * 
 * 第一种结果: fast = NULL，说明没有环形链表
 * 第二种结果: slow = fast，说明在环形链表相遇
 *      设链表头部到环形链表入口有 a 个节点（不计环形链表入口节点）
 *      设环形链表有 b 个节点
 *          - 令 low = s, 则 fast = 2s
 *      相遇说明在环形链表内走了 n 圈（这里的 n 是常数）
 *          - 令 fast = s + nb, 则 s = nb, fast = 2nb
 *      根据链表头部到链表入口的步数 a + nb, 此时 low 和 fast 都是 nb(2nb), 
 *          - 则当前位置到链表入口 distance = a, 与链表头部到环形链表入口一样 a
 *      所以只需要其中一个在置换成头部，两个相等即位置是环形链表入口
 * 
 * 总结：头指针距环入口点前的距离 和 相遇点距离入口的的距离 相等
 */
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    // 求相遇位置
    while (1) {
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    // 头指针距环入口点前的距离 和 相遇点距离入口的的距离 相等，得到环形链表入口
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    int              arr[] = {3, 2, 0, -4};
    int              n     = sizeof(arr) / sizeof(arr[0]);
    int              pos   = 1;
    struct ListNode* head  = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* ret   = (struct ListNode*)malloc(sizeof(struct ListNode*));

    createList(arr, n, pos, head);
    // displayList(head->next);
    ret = detectCycle(head);
    printf("%d", ret->val);

    return 0;
}