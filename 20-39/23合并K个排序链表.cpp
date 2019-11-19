//方法一：分治（两两合并） 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL)								
        return l2;
    if(l2==NULL)								
        return l1;
    if(l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next,l2);		//递归 
        return l1;
    }else{
        l2->next = mergeTwoLists(l1,l2->next);		//递归 
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
        return mergeTwoLists(lists[0], lists[1]);	//合并 
    }
    
    leftList = mergeKLists(lists, listsSize / 2);	//递归，一直划分到两两链表 
    rightList = mergeKLists(lists + listsSize / 2, listsSize - listsSize / 2);	//递归，一直划分到两两链表 
    
    return mergeTwoLists(leftList, rightList);		//返回最后两个链表合并结果 
}

//方法二： 纯递归 
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode* temp = NULL;
    int val = INT_MAX;								//最大值 
    int pos = -1;									//位置信息
    for(int i = 0; i < listsSize;i++){				//遍历每条链表 
        if(lists[i]){								//直到所有遍历完，NULL 结束 
            if(val > lists[i]->val){				//判断每条链表当前位置最小值 
                val = lists[i]->val;
                pos = i;							//把最小值的下标给 pos 
            }
        }
    }
    if(pos != -1){									//有数据返回 
        temp = lists[pos];							//将几条链表中这一位置最小的拼接到 temp 链表中 
        lists[pos] = lists[pos]->next;
        temp->next = mergeKLists(lists,listsSize);	//递归 
    }
    
    return temp;
}
