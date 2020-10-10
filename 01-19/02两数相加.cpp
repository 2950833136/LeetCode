#include <malloc.h>
#include <stdio.h>

/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

//创建链表
struct ListNode *createNode(int Array[], int size) {
    struct ListNode *head;
    struct ListNode *p;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    p = head;

    for (int i = 0; i < size; i++) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = Array[i];
        node->next = NULL;

        p->next = node;  //尾插法
        p = node;
    }
    return head->next;  //返回头结点
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *head;                                      // 头结点
    struct ListNode *p;                                         // 插入结点
    head = (struct ListNode *)malloc(sizeof(struct ListNode));  // 申请空间
    head->next = NULL;                                          // 初始化
    p = head;

    int addNum = 0;  // 记录上一个节点的和是否有进位
    int sum = 0;     // 每个节点当前位的和
    while (l1 != NULL || l2 != NULL || addNum == 1) {
        //新建一个结点
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = 0;
        node->next = NULL;

        if (l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val;
            sum += addNum;
            int val = sum % 10;  //超过十，求10的余数即个位
            node->val = val;
            l1 = l1->next;
            l2 = l2->next;
        } else if (l1 != NULL && l2 == NULL) {
            sum = l1->val;
            sum += addNum;
            int val = sum % 10;  //超过十，求10的余数即个位
            node->val = val;
            l1 = l1->next;
        } else if (l1 == NULL && l2 != NULL) {
            sum = l2->val;
            sum += addNum;
            int val = sum % 10;  //超过十，求10的余数即个位
            node->val = val;
            l2 = l2->next;
        } else {
            node->val = addNum;  //两个链表都遍历结束但尾节点相加还有进位
            addNum = 0;
            sum = 0;
        }
        addNum = sum >= 10 ? 1 : 0;  //判断是否进位
        // printf("%d\n", node->val);   //尾插法
        p->next = node;
        p = node;
    }
    return head->next;  //返回头结点
}

void display(struct ListNode *l) {
    while (l != NULL) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
}

int main() {
    int array1[] = {2, 4, 3};
    int array2[] = {5, 6, 4};
    int size1 = sizeof(array1) / sizeof(int);
    int size2 = sizeof(array2) / sizeof(int);
    struct ListNode *l1 = createNode(array1, size1);
    // 遍历查看结果，但使用时不能遍历，不然指针结点会移到最后，导致空
    display(l1);

    struct ListNode *l2 = createNode(array2, size2);
    display(l2);

    struct ListNode *L = addTwoNumbers(l1, l2);
    display(L);

    return 0;
}