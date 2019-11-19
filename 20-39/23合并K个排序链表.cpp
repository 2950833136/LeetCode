//����һ�����Σ������ϲ��� 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL)								
        return l2;
    if(l2==NULL)								
        return l1;
    if(l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next,l2);		//�ݹ� 
        return l1;
    }else{
        l2->next = mergeTwoLists(l1,l2->next);		//�ݹ� 
        return l2;
    }
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *leftList = NULL;
    struct ListNode *rightList = NULL;

    if (listsSize < 1) {
        return NULL;
    }
    if (listsSize == 1) {
        return lists[0];
    }
    if (listsSize == 2) {
        return mergeTwoLists(lists[0], lists[1]);	//�ϲ� 
    }
    
    leftList = mergeKLists(lists, listsSize / 2);	//�ݹ飬һֱ���ֵ��������� 
    rightList = mergeKLists(lists + listsSize / 2, listsSize - listsSize / 2);	//�ݹ飬һֱ���ֵ��������� 
    
    return mergeTwoLists(leftList, rightList);		//���������������ϲ���� 
}

//�������� ���ݹ� 
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode* temp = NULL;
    int val = INT_MAX;								//���ֵ 
    int pos = -1;									//λ����Ϣ
    for(int i = 0; i < listsSize;i++){				//����ÿ������ 
        if(lists[i]){								//ֱ�����б����꣬NULL ���� 
            if(val > lists[i]->val){				//�ж�ÿ������ǰλ����Сֵ 
                val = lists[i]->val;
                pos = i;							//����Сֵ���±�� pos 
            }
        }
    }
    if(pos != -1){									//�����ݷ��� 
        temp = lists[pos];							//��������������һλ����С��ƴ�ӵ� temp ������ 
        lists[pos] = lists[pos]->next;
        temp->next = mergeKLists(lists,listsSize);	//�ݹ� 
    }
    
    return temp;
}
