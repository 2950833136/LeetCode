#include <malloc.h>
#include <stdio.h>

struct ListNode {
    int              val;
    struct ListNode* next;
};

//尾插法
void CreateListR(struct ListNode* L, int* array, int n) {
    struct ListNode* r = (struct ListNode*)malloc(sizeof(struct ListNode)); //创建头结点
    r                  = L;                                                 //r 始终指向尾结点，初始时指向头结点 （头结点序号为 0）
    for (int i = 0; i < n; i++) {                                           //循环建立数据节点 s
        struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
        s->val             = array[i]; //赋值
        r->next            = s;        //将结点 s 插入到结点 r 之后
        r                  = s;
    }
    r->next = NULL; //尾结点其 next 域置为 NULL
}

//输出线性表
void Display(struct ListNode* L) {
    struct ListNode* p = L; //p 指向首结点 （首结点序号为 1）
    while (p != NULL) {     //不为空，依次遍历
        printf("%d ", p->val);
        p = p->next; //p 移向下一个节点
    }
    printf("\n");
}

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* pre  = NULL; //定义一个节点
    struct ListNode* curr = head; //curr 表示链表
    while (curr != NULL) {
        struct ListNode* next = curr->next; //记录洗一个节点

        curr->next = pre;  //当前节点连接到 pre 前面
        pre        = curr; //pre 向前移动

        curr = next; //curr 指向下一个节点
    }
    return pre;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next            = head;
    struct ListNode* pre   = dummy; //记录前驱节点
    struct ListNode* post  = dummy; //记录后继节点

    while (post->next != NULL) {
        for (int i = 0; i < k && post != NULL; i++) {
            post = post->next; //后继节点向后移动 k 位
        }
        if (post == NULL) { //跳出循环，最后剩余的节点保持原有顺序
            break;
        }
        struct ListNode* start = pre->next;      //开始节点是前驱节点
        struct ListNode* next  = post->next;     //记录下一个开始节点
        post->next             = NULL;           //把 k 个节点封装成一个链表
        pre->next              = reverse(start); //反转这 k 个节点的链表，并连到 pre 后面

        start->next = next;  //下一次开始节点
        pre         = start; //下一次前驱节点
        post        = start; //下一次后继节点
    }
    return dummy->next;
}

int main() {
    struct ListNode* L       = (struct ListNode*)malloc(sizeof(struct ListNode));
    int              array[] = {1, 2, 3, 4, 5};
    int              n       = sizeof(array) / sizeof(array[0]);
    int              k       = 3;
    CreateListR(L, array, n);
    Display(L->next);
    struct ListNode* reverseK = reverseKGroup(L->next, k);
    Display(reverseK);
    return 0;
}
