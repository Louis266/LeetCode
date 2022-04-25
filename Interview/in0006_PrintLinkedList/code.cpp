#include <bits/stdc++.h>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(NULL) {}
};

vector<int> reversePrint(ListNode *head)
{
    stack<int> s;
    while (head!=NULL)
    {
        s.push(head->val);
        head = head->next;
    }
    vector<int> res;
    while (!s.empty())
    {
        res.push_back(s.top());
        s.pop();
    }
    return res;
}
