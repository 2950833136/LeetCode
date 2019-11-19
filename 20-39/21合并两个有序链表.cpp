#include<stdio.h>
#include<malloc.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

//β�巨
void CreateListR(struct ListNode*& L, int array[], int n) {
	ListNode* s, * r;
	L = (ListNode*)malloc(sizeof(ListNode));	//����ͷ���
	r = L;										//r ʼ��ָ��β��㣬��ʼʱָ��ͷ��� ��ͷ������Ϊ 0�� 
	for (int i = 0; i < n; i++) {				//ѭ���������ݽڵ� s
		s = (ListNode*)malloc(sizeof(ListNode));
		s->val = array[i];						//��ֵ 
		r->next = s;							//����� s ���뵽��� r ֮�� 
		r = s;
	}
	r->next = NULL;								//β����� next ����Ϊ NULL 
}

//������Ա�
void Display(struct ListNode* L) {
	ListNode* p = L->next;						//p ָ���׽�� ���׽�����Ϊ 1�� 
	while (p != NULL) {							//��Ϊ�գ����α��� 
		printf("%d", p->val);
		if (p->next != NULL) {
			printf("->");
		}
		p = p->next;							//p ������һ���ڵ� 
	}
	printf("\n");
}

//���� 
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
//	struct ListNode* prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* prev = prehead;			//prehead ��ͷ��㣬���� prev ���ƴ�ӣ�β�巨 �� 
//	while (l1 != NULL && l2 != NULL) {
//		if (l1->val <= l2->val) {				//l1 <= l2���� l1 �ӵ� prev ���� 
//			prev->next = l1;
//			l1 = l1->next;						//l1 ����һ����� 
//		}
//		else {									//���� �� l2 �ӵ� prev ���� 
//			prev->next = l2;
//			l2 = l2->next;						//l2 ����һ�����
//		}
//		prev = prev->next;						//prev ���� 
//	}
//	prev->next = l1 == NULL ? l2 : l1;			//������һ��Ϊ�ս�������� l1==NULL���Ͱ� l2 ƴ�ӵ� prev ���棬����Ͱ� l1 ƴ�ӵ� prev ����
//	return prehead->next;
//}

//�ݹ�
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL)								
        return l2;
    if(l2==NULL)								
        return l1;
    if(l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next,l2);	//�ݹ� 
        return l1;
    }else{
        l2->next = mergeTwoLists(l1,l2->next);	//�ݹ� 
        return l2;
    }
}

int main() {
	int array1[] = { 1,2,4 };
	int array2[] = { 1,3,4 };
	int n1 = sizeof(array1) / sizeof(int);
	int n2 = sizeof(array2) / sizeof(int);
	struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	CreateListR(l1, array1, n1);
	CreateListR(l2, array2, n2);
	printf("����������ɹ�!\n");
	printf("���������\n");
	Display(l1);
	Display(l2);

	struct ListNode* l3 = mergeTwoLists(l1, l2);
	//���ֻ�� l3����֪��Ϊʲô��һ���� 0�����Ը�Ϊ l3->next 
	Display(l3->next);
	return 0;
}
