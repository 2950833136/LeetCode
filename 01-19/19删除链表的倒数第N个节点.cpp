#include<stdio.h>
#include<malloc.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

//struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
//	struct ListNode* pTemp = (struct ListNode*)malloc(sizeof(struct ListNode));		//���������ڵ� 
//	struct ListNode* pNode = (struct ListNode*)malloc(sizeof(struct ListNode));
//	int m = 0;
//	pTemp = head;																	//ָ��ͷָ�� 
//	int i;
//	while (pTemp != NULL) {															//��������ĳ���
//		m++;
//		pTemp = pTemp->next;
//	}
//	i = m - n + 1;																	//����ɾ���ĸ��ڵ� 
//	if (i == 1) {																	//�����ͷ
//		pTemp = head;
//		head = head->next;
//		free(pTemp);
//		pTemp = NULL;
//	}
//	else {																			//�������ͷ
//		pTemp = head;
//		for (int j = 1; j < i - 1; j++) {
//			pTemp = pTemp->next;
//		}
//		pNode = pTemp->next;
//		pTemp->next = pTemp->next->next;											//ɾ��ָ���ڵ� 
//		free(pNode);
//		pNode = NULL;
//	}
//	return head;
//}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	int i;
	struct ListNode* first = NULL;					//���������ڵ� 
	struct ListNode* second = NULL;
	first = head;									//ָ��ͷ��� 
	second = head;

	for (i = 0; i < n; i++) {						//�����������������һ����� 
		if (first != NULL) {						//�˳����� 
			first = first->next;
		}
		else {
			return head;
		}
	}

	if (first == NULL) {
		return head->next;
	}

	while (first->next != NULL) {					//��һ���ڵ����Ϊ��˵����������һ���ڵ� 
		first = first->next;
		second = second->next;
	}
	second->next = (second->next)->next;			//ɾ���ڵ㣬�ڶ����ڵ�ĺ�һ�� 

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
