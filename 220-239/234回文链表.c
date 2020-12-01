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
 * 方法一：将值复制到数组中后用双指针法
 *  - 用数组把链表数值存储
 *  - 然后循环遍历数组比较
 */
// bool isPalindrome(struct ListNode* head) {
//     int node[50001];
//     int index = 0;
//     while (head != NULL) {
//         node[index++] = head->val;
//         head          = head->next;
//     }
//     for (int i = 0, j = index - 1; i < j; i++, j--) {
//         if (node[i] != node[j]) {
//             return false;
//         }
//     }
//     return true;
// }

/**
 * 方法二：递归
 *  - 前驱节点作为全局变量
 *  - 递归遍历下一个节点，不满足条件回溯 false，满足回溯 true
 *  - 这样就会遍历完 frontPointer 和 currentNode 都会遍历整个指针
 */
// struct ListNode* frontPointer;

// bool recursivelyCheck(struct ListNode* currentNode) {
//     if (currentNode != NULL) {
//         if (!recursivelyCheck(currentNode->next)) {
//             return false;
//         }
//         if (currentNode->val != frontPointer->val) {
//             return false;
//         }
//         frontPointer = frontPointer->next;
//     }
//     return true;
// }

// bool isPalindrome(struct ListNode* head) {
//     frontPointer = head;
//     return recursivelyCheck(head);
// }

/**
 * 方法三：中分链表，逆转判断
 *  - 找到前半部分链表的尾节点
 *  - 反转后半部分链表
 *  - 判断是否回文
 *  - 恢复链表
 *  - 返回结果
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
// temp 保存下一个节点，其他节点 next 连接上一个节点
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* temp = curr->next;
        curr->next            = prev;
        prev                  = curr;
        curr                  = temp;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL) {
        return true;
    }

    // 找到前半部分链表的尾节点并反转后半部分链表
    struct ListNode* mid  = middleNode(head);
    struct ListNode* last = reverseList(mid->next);

    // 判断是否回文
    bool             ans = true;
    struct ListNode* p1  = head;
    struct ListNode* p2  = last;
    while (ans && p2 != NULL) {
        if (p1->val != p2->val) {
            ans = false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // 还原链表并返回结果
    mid->next = reverseList(last);
    return ans;
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