#include <iostream>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* beefore2021
ListNode *reverseList(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
*/

// 2022 double pointers
/*
ListNode *reverseList(ListNode * head) {
    ListNode* temp;
    ListNode* cur = head;
    ListNode* pre = nullptr;

    while (cur)
    {
        temp = cur->next;
        cur->next = pre;

        pre = cur;
        cur = temp;
    }
    
    return pre;
}
*/

// 2022 recursion
ListNode* reverse(ListNode* pre, ListNode* cur) {
    if (cur == nullptr)
    {
        return pre;
    }
    ListNode* temp = cur->next;
    cur->next = pre;

    return reverse(cur, temp);
    
}

ListNode* reverseList(ListNode* head) {
    return reverse(nullptr, head);
}

void printListNode(ListNode* head)
{
    ListNode* temp = head;
    while (temp)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << endl;
    
}

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);

    a->next = b;
    b->next = c;

    printListNode(a);

    ListNode* head = reverseList(a);

    printListNode(head);
}