#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int       val;
    ListNode *next;
    ListNode()
        : val(0), next(nullptr) {}
    ListNode(int x)
        : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next)
        : val(x), next(next) {}
};

ListNode *createList(vector<int> arr) {
    ListNode *head = new ListNode();
    ListNode *curr = head;
    for (int i = 0; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr       = curr->next;
    }
    return head->next;
}

void traversal(ListNode *head) {
    ListNode *temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

/**
 * 迭代
 * 先拷贝原链表，在判断删除（跳过覆盖）
 *      cur->next = cur->next->next;
 */
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *cur       = dummyHead;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
};

int main() {
    vector<int> headArr = { 1, 2, 6, 3, 4, 5, 6 };
    int         val     = 6;
    ListNode *  head    = createList(headArr);

    Solution s;
    traversal(s.removeElements(head, val));

    return 0;
}