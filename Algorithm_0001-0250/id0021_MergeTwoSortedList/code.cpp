#include <cstdlib>
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    ListNode *res = l1->val > l2->val ? l2 : l1;

    if (l1->val > l2->val)
    {
        l2 = l2->next;
    }
    else
    {
        l1 = l1->next;
    }

    ListNode *i = res;
    while (l1 != NULL && l2 != NULL)
    {

        if (l1->val > l2->val)
        {
            i->next = l2;
            i = i->next;
            l2 = l2->next;
        }
        else
        {
            i->next = l1;
            i = i->next;
            l1 = l1->next;
        }
    }

    if (l1 != NULL)
    {
        i->next = l1;
    }

    if (l2 != NULL)
    {
        i->next = l2;
    }

    return res;
}

int main()
{
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(4);
    ListNode l4(1);
    ListNode l5(3);
    ListNode l6(4);

    l1.next = &l2;
    l2.next = &l3;

    l4.next = &l5;
    l5.next = &l6;

    ListNode *res = mergeTwoLists(&l1, nullptr);

    while (res != NULL)
    {
        cout << res->val << "->";
        res = res->next;
    }
    cout << endl;
}
