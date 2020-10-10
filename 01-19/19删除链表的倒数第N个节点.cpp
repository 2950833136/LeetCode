#include<stdio.h>
#include<malloc.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

//struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
//	struct ListNode* pTemp = (struct ListNode*)malloc(sizeof(struct ListNode));		//定义两个节点 
//	struct ListNode* pNode = (struct ListNode*)malloc(sizeof(struct ListNode));
//	int m = 0;
//	pTemp = head;																	//指向头指针 
//	int i;
//	while (pTemp != NULL) {															//计算链表的长度
//		m++;
//		pTemp = pTemp->next;
//	}
//	i = m - n + 1;																	//计算删除哪个节点 
//	if (i == 1) {																	//如果是头
//		pTemp = head;
//		head = head->next;
//		free(pTemp);
//		pTemp = NULL;
//	}
//	else {																			//如果不是头
//		pTemp = head;
//		for (int j = 1; j < i - 1; j++) {
//			pTemp = pTemp->next;
//		}
//		pNode = pTemp->next;
//		pTemp->next = pTemp->next->next;											//删除指定节点 
//		free(pNode);
//		pNode = NULL;
//	}
//	return head;
//}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	int i;
	struct ListNode* first = NULL;					//定义两个节点 
	struct ListNode* second = NULL;
	first = head;									//指向头结点 
	second = head;

	for (i = 0; i < n; i++) {						//倒数几个，即离最后一个间隔 
		if (first != NULL) {						//退出条件 
			first = first->next;
		}
		else {
			return head;
		}
	}

	if (first == NULL) {
		return head->next;
	}

	while (first->next != NULL) {					//第一个节点后面为空说明这就是最后一个节点 
		first = first->next;
		second = second->next;
	}
	second->next = (second->next)->next;			//删除节点，第二个节点的后一个 

	return head;
}

void CreateList(struct ListNode*& head, int length) {
	struct ListNode* s, * r;
	r = head;
	for (int i = 1; i <= length; i++) {
		s = (struct ListNode*)malloc(sizeof(struct ListNode));
		s->val = i;
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

int main() {
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	CreateList(head, 5);
	head = head->next;
	//	while(head!=NULL){
	//		printf("%d ",head->val);
	//		head=head->next;
	//	}
	struct ListNode* res = removeNthFromEnd(head, 2);
	while (res != NULL) {
		printf("%d ", res->val);
		res = res->next;
	}
	return 0;
}
