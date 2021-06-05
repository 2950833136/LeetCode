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

int main() {
    vector<int> headArr = { 1, 2, 6, 3, 4, 5, 6 };
    ListNode *  head    = createList(headArr);

    traversal(head);

    return 0;
}