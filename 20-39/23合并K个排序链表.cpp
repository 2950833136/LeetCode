#include <limits.h>
#include <malloc.h>
#include <stdio.h>

struct ListNode {
    int              val;
    struct ListNode* next;
};

//方法一：分治（两两合并）
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2); //递归
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next); //递归
        return l2;
    }
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* leftList  = NULL;
    struct ListNode* rightList = NULL;
    if (listsSize < 1) {
        return NULL;
    }
    if (listsSize == 1) {
        return lists[0];
    }
    if (listsSize == 2) {
        return mergeTwoLists(lists[0], lists[1]); //合并
    }
    leftList  = mergeKLists(lists, listsSize / 2);                             //递归，一直划分到两两链表
    rightList = mergeKLists(lists + listsSize / 2, listsSize - listsSize / 2); //递归，一直划分到两两链表
    return mergeTwoLists(leftList, rightList);                                 //返回最后两个链表合并结果
}

// //方法二： 纯递归
// struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
//     struct ListNode* temp = NULL;
//     int              val  = INT_MAX;      //最大值
//     int              pos  = -1;           //位置信息
//     for (int i = 0; i < listsSize; i++) { //遍历每条链表
//         if (lists[i]) {                   //直到所有遍历完，NULL 结束
//             if (val > lists[i]->val) {    //判断每条链表当前位置最小值
//                 val = lists[i]->val;
//                 pos = i; //把最小值的下标给 pos
//             }
//         }
//     }
//     if (pos != -1) {             //有数据返回
//         temp       = lists[pos]; //将几条链表中这一位置最小的拼接到 temp 链表中
//         lists[pos] = lists[pos]->next;
//         temp->next = mergeKLists(lists, listsSize); //递归
//     }

//     return temp;
// }

//输出
void Display(struct ListNode* L) {
    ListNode* p = L;    //p 指向首结点 （首结点序号为 1）
    while (p != NULL) { //不为空，依次遍历
        printf("%d", p->val);
        if (p->next != NULL) {
            printf("->");
        }
        p = p->next; //p 移向下一个节点
    }
    printf("\n");
}
//创建
void creatList(struct ListNode* list, int arr[], int arrColSize) {
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode) * arrColSize);
    p                  = list;
    list->val          = arr[0];
    list->next         = NULL;
    for (int i = 1; i < arrColSize; i++) {
        struct ListNode* q = (struct ListNode*)malloc(sizeof(struct ListNode));
        q->val             = arr[i];
        p->next            = q;
        p                  = q;
    }
    p->next = NULL;
    // Display(list);
}

int main() {
    int               arr[][3] = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    int               arrSize  = sizeof(arr) / sizeof(arr[0]);
    int               arrNum   = 0;
    struct ListNode** lists    = (struct ListNode**)malloc(sizeof(struct ListNode*) * arrSize);
    for (int i = 0; i < arrSize; i++) {
        int arrColSize = 0;
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] != 0) {
                arrColSize++;
                arrNum++;
            }
        }
        lists[i] = (struct ListNode*)malloc(sizeof(struct ListNode) * arrColSize);
        creatList(lists[i], arr[i], arrColSize);
    }

    struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode) * arrNum);
    ret                  = mergeKLists(lists, arrSize);
    Display(ret);

    return 0;
}
