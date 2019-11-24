#include<stdio.h>
#include<malloc.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

//β�巨
void CreateListR(struct ListNode*& L, int array[], int n) {
	struct ListNode* s, * r;
	L = (struct ListNode*)malloc(sizeof(struct ListNode));	//����ͷ���
	r = L;										//r ʼ��ָ��β��㣬��ʼʱָ��ͷ��� ��ͷ������Ϊ 0�� 
	for (int i = 0; i < n; i++) {				//ѭ���������ݽڵ� s
		s = (struct ListNode*)malloc(sizeof(struct ListNode));
		s->val = array[i];						//��ֵ 
		r->next = s;							//����� s ���뵽��� r ֮�� 
		r = s;
	}
	r->next = NULL;								//β����� next ����Ϊ NULL 
}

//������Ա�
void Display(ListNode* L) {
	struct ListNode* p = L;						//p ָ���׽�� ���׽�����Ϊ 1�� 
	while (p != NULL) {							//��Ϊ�գ����α��� 
		printf("%d ", p->val);
		p = p->next;							//p ������һ���ڵ� 
	}
	printf("\n");
}

//�ݹ�
struct ListNode* swapPairs(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {	//Ϊ�ջ�ֻ��һ���Ͳ��ý��� 
		return head;
	}
	struct ListNode* node1 = head;				//��һ���ڵ� 
	struct ListNode* node2 = head->next;		//�ڶ����ڵ� 
	struct ListNode* next = node2->next;		//�����¼�ڶ����ڵ��Ľڵ�����
	
	node2->next = node1;						//�ڶ����ڵ�ָ���һ���ڵ�
	node1->next = swapPairs(next);				//ԭ��һ���ڵ�ָ����棨�����ģ��Ľڵ� 
	return node2;								 
}

//�ǵݹ� 
//struct ListNode* swapPairs(struct ListNode* head) {
//	//����ͷ�ڵ� 
//	struct ListNode* lhead = (struct ListNode*)malloc(sizeof(struct ListNode));
//	//pre���ڸ�ͷ�ڵ����ӣ�node1��node2���ڽ����ڵ㣬next���ڿ�ʼ��һ�ν���
//	struct ListNode* pre, * node1, * node2, *next;
//	lhead->next = head;							//���ӵ�ԭ������ 
//	pre = lhead;
//	while (pre->next != NULL && pre->next->next != NULL) {
//		node1 = pre->next;						//��һ���ڵ� 
//		node2 = pre->next->next;				//�ڶ����ڵ� 
//		next = node2->next;						//�����¼�ڶ����ڵ��Ľڵ�����
//
//		pre->next = node2;						//ǰ���ڵ������ڶ����ڵ�
//		node2->next = node1;					//�ڶ����ڵ�������һ���ڵ�
//		node1->next = next;						//��һ���ڵ���������ڵ�
//		pre = node1;							//��ʱǰ���ڵ㻻�ɵ�һ���ڵ㣬��β�巨��
//	}
//	return lhead->next;
//}

int main() {
	struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
	int array[] = { 1,2,3,4 };
	int n = sizeof(array) / sizeof(array[0]);
	CreateListR(L, array, n);
	Display(L->next);

	struct ListNode* swapL = swapPairs(L->next);
	Display(swapL);
	return 0;
}
