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

ListNode *middleNode(ListNode *head)
{
    //int i = 1;
    if (head->next == nullptr)
    {
        return head;
    }
    if (head->next->next == nullptr)
    {
        return head->next;
    }
    int count = 2;
    
    head = head->next;
    while (head->next != nullptr)
    {
        ListNode *temp = head;
        for (int i = 0; i < count - 2; i++)
        {
            temp = temp->next;
        }
        if (temp->next == nullptr || temp->next->next == nullptr)
        {
            return head;
        }

        head = head->next;
        count++;
    }
    return NULL;
}