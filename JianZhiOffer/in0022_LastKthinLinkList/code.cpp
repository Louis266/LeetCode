#include <stdlib.h>
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getKthFromEnd(ListNode *head, int k)
{
    ListNode *n = head;
    for (int i = 0; i < k; i++)
    {
        n = n->next;
    }

    ListNode *i = head;

    while (n != NULL)
    {
        n = n->next;
        i = i->next;
    }

    return i;
    
    
}