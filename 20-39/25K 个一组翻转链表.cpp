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
	ListNode* p = L;							//p ָ���׽�� ���׽�����Ϊ 1�� 
	while (p != NULL) {							//��Ϊ�գ����α��� 
		printf("%d ", p->val);
		p = p->next;							//p ������һ���ڵ� 
	}
	printf("\n");
}

struct ListNode* reverse(struct ListNode* head) {
	struct ListNode* pre = NULL;				//����һ���ڵ� 
	struct ListNode* curr = head;				//curr ��ʾ���� 
	while (curr != NULL) {
		struct ListNode* next = curr->next;		//��¼ϴһ���ڵ�

		curr->next = pre;						//��ǰ�ڵ����ӵ� pre ǰ��
		pre = curr;								//pre ��ǰ�ƶ�
		
		curr = next;							//curr ָ����һ���ڵ�
	}
	return pre;	
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
	dummy->next = head;
	struct ListNode* pre = dummy;				//��¼ǰ���ڵ� 
	struct ListNode* post = dummy;				//��¼��̽ڵ� 

	while (post->next != NULL) {
		for (int i = 0; i < k && post != NULL; i++) {
			post = post->next;					//��̽ڵ�����ƶ� k λ 
		}
		if (post == NULL) {						//����ѭ�������ʣ��Ľڵ㱣��ԭ��˳�� 
			break;
		}
		struct ListNode* start = pre->next;		//��ʼ�ڵ���ǰ���ڵ� 
		struct ListNode* next = post->next;		//��¼��һ����ʼ�ڵ� 
		post->next = NULL;						//�� k ���ڵ��װ��һ������ 
		pre->next = reverse(start);				//��ת�� k ���ڵ������������ pre ����
		
		start->next = next;						//��һ�ο�ʼ�ڵ�
		pre = start;							//��һ��ǰ���ڵ� 
		post = start;							//��һ�κ�̽ڵ� 
	}
	return dummy->next;
}

int main() {
	struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
	int array[] = { 1,2,3,4,5 };
	int n = sizeof(array) / sizeof(array[0]);
	int k = 3;
	CreateListR(L, array, n);
	Display(L->next);
	struct ListNode* reverseK = reverseKGroup(L->next, k);
	Display(reverseK);
	return 0;
}
