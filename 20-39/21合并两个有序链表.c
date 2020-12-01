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
    struct ListNode* p = L->next; //p 指向首结点 （首结点序号为 1）
    while (p != NULL) {           //不为空，依次遍历
        printf("%d", p->val);
        if (p->next != NULL) {
            printf("->");
        }
        p = p->next; //p 移向下一个节点
    }
    printf("\n");
}

//迭代
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
//	struct ListNode* prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* prev = prehead;			//prehead 是头结点，利用 prev 结点拼接（尾插法 ）
//	while (l1 != NULL && l2 != NULL) {
//		if (l1->val <= l2->val) {				//l1 <= l2，把 l1 接到 prev 后面
//			prev->next = l1;
//			l1 = l1->next;						//l1 后移一个结点
//		}
//		else {									//否则， 把 l2 接到 prev 后面
//			prev->next = l2;
//			l2 = l2->next;						//l2 后移一个结点
//		}
//		prev = prev->next;						//prev 后移
//	}
//	prev->next = l1 == NULL ? l2 : l1;			//其中有一个为空结束，如果 l1==NULL，就把 l2 拼接到 prev 后面，否则就把 l1 拼接到 prev 后面
//	return prehead->next;
//}

//递归
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

int main() {
    int              array1[] = {1, 2, 4};
    int              array2[] = {1, 3, 4};
    int              n1       = sizeof(array1) / sizeof(int);
    int              n2       = sizeof(array2) / sizeof(int);
    struct ListNode* l1       = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l2       = (struct ListNode*)malloc(sizeof(struct ListNode));
    CreateListR(l1, array1, n1);
    CreateListR(l2, array2, n2);
    printf("创建单链表成功!\n");
    printf("输出单链表\n");
    Display(l1);
    Display(l2);

    struct ListNode* l3 = mergeTwoLists(l1, l2);
    //如果只是 l3，不知道为什么第一个是 0，所以改为 l3->next
    Display(l3->next);
    return 0;
}
