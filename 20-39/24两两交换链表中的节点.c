#include <malloc.h>
#include <stdio.h>

struct ListNode {
    int              val;
    struct ListNode* next;
};

//尾插法
void CreateListR(struct ListNode** L, int array[], int n) {
    struct ListNode *s, *r;
    *L = (struct ListNode*)malloc(sizeof(struct ListNode)); // 创建头结点
    r = *L;                                                 // r 始终指向尾结点，初始时指向头结点 （头结点序号为 0）
    for (int i = 0; i < n; i++) {                          // 循环建立数据节点 s
        s       = (struct ListNode*)malloc(sizeof(struct ListNode));
        s->val  = array[i]; // 赋值
        r->next = s;        // 将结点 s 插入到结点 r 之后
        r       = s;
    }
    r->next = NULL; // 尾结点其 next 域置为 NULL
}

//输出线性表
void Display(struct ListNode* L) {
    struct ListNode* p = L;    // p 指向首结点 （首结点序号为 1）
    while (p != NULL) {        // 不为空，依次遍历
        printf("%d ", p->val); // 打印输出
        p = p->next;           // p 移向下一个节点
    }
    printf("\n");
}

/**
 * 题解
 */
// 递归
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { // 为空或只有一个就不用交换
        return head;
    }
    struct ListNode* node1 = head;            // 第一个节点
    struct ListNode* node2 = head->next;      // 第二个节点
    struct ListNode* next  = node2->next;     // 保存记录第二个节点后的节点引用
    node2->next            = node1;           // 第二个节点指向第一个节点
    node1->next            = swapPairs(next); // 原第一个节点指向后面（交换的）的节点
    return node2;
}

// 非递归
// struct ListNode* swapPairs(struct ListNode* head) {
//     // 定义头节点
//     struct ListNode* lhead = (struct ListNode*)malloc(sizeof(struct ListNode));
//     // pre用于给头节点连接，node1、node2用于交换节点，next用于开始下一次交换
//     struct ListNode *pre, *node1, *node2, *next;
//     lhead->next = head; //连接到原来链表
//     pre         = lhead;
//     while (pre->next != NULL && pre->next->next != NULL) {
//         node1       = pre->next;       // 第一个节点
//         node2       = pre->next->next; // 第二个节点
//         next        = node2->next;     // 保存记录第二个节点后的节点引用
//         pre->next   = node2;           // 前驱节点连到第二个节点
//         node2->next = node1;           // 第二个节点连到第一个节点
//         node1->next = next;            // 第一个节点连到后面节点
//         pre         = node1;           // 此时前驱节点换成第一个节点，（尾插法）
//     }
//     return lhead->next;
// }

int main() {
    struct ListNode* L       = (struct ListNode*)malloc(sizeof(struct ListNode));
    int              array[] = {1, 2, 3, 4};
    int              n       = sizeof(array) / sizeof(array[0]);
    CreateListR(&L, array, n);
    Display(L->next);

    struct ListNode* swapL = swapPairs(L->next);
    Display(swapL);
    return 0;
}
