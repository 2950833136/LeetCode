#include<stdio.h>
#include<malloc.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

//�������� 
struct ListNode *createNode(int Array[],int size)
{
    struct ListNode *head;
    struct ListNode *p;
    head=(struct ListNode *)malloc(sizeof(struct ListNode));
    head->next=NULL;
    p=head;

    for(int i=0;i<size;i++)
    {
        struct ListNode *node=(struct ListNode *)malloc(sizeof(struct ListNode));	
        node->val=Array[i];										
        node->next=NULL;

        p->next=node;												//β�巨 
        p=node;
    }
    printf("�����ɹ���\n");
    return head->next;												//����ͷ���
}
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	struct ListNode *head;					//ͷ��� 
    struct ListNode *p;						//������ 
    head=(struct ListNode *)malloc(sizeof(struct ListNode));
    head->next=NULL;						//��ʼ�� 
    p=head;
    
	int addNum = 0;							//��¼��һ���ڵ�ĺ��Ƿ��н�λ  
	int sum = 0;							//ÿ���ڵ㵱ǰλ�ĺ� 
	while (l1!=NULL || l2!=NULL || addNum==1) {
		//�½�һ����� 
		struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
		node->val = 0; 
		node->next = NULL;
		
		if (l1!=NULL&&l2!=NULL) { 
	      	sum = l1->val + l2->val; 
			sum += addNum; 
			int val = sum%10; 				//����ʮ����10����������λ 
			node->val = val; 
			l1 = l1->next; 
			l2 = l2->next; 
		}
		else if (l1!=NULL&&l2==NULL) { 
			sum = l1->val; 
			sum += addNum; 
			int val = sum%10;				//����ʮ����10����������λ  
			node->val = val; 
			l1 = l1->next; 
		}
		else if (l1==NULL&&l2!=NULL) { 
			sum = l2->val; 
			sum += addNum; 
			int val = sum%10; 				//����ʮ����10����������λ 
			node->val = val; 
			l2 = l2->next; 
		}
		else {
	      	node->val = addNum;				//������������������β�ڵ���ӻ��н�λ  
			addNum = 0; 
			sum = 0; 
		} 
		addNum = sum>=10 ? 1 : 0; 			//�ж��Ƿ��λ 
		
		printf("%d\n",node->val);			//β�巨
	    p->next=node;
		p=node;
	}
	printf("��ӳɹ���\n");
	return head->next;						//����ͷ��� 
}

int main(){
	int array1[]={2,4,3};
	int array2[]={5,6,4};
	int size1=sizeof(array1)/sizeof(int);
	int size2=sizeof(array2)/sizeof(int);
	struct ListNode* l1=createNode(array1,size1);		//�����鿴�������ʹ��ʱ���ܱ�������Ȼָ������Ƶ���󣬵��¿� 
//	while(l1!=NULL){
//        printf("%d\n",l1->val);
//        l1=l1->next;
//    }
    
	struct ListNode* l2=createNode(array2,size2);
//	while(l2!=NULL){
//        printf("%d\n",l2->val);
//        l2=l2->next;
//    }
	
	struct ListNode* L=addTwoNumbers(l1,l2);
	while(L!=NULL){
        printf("%d",L->val);
        L=L->next;
    }
    
	return 0; 
}


/*
�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�
�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��

ʾ����
���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807
*/
