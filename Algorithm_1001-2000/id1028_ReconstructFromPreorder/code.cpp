#include <cstdlib>
#include <string>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printTree(TreeNode *t)
{
    if (t == nullptr)
    {
        cout << "ERROR" << endl;
    }

    queue<TreeNode *> que;
    que.push(t);

    while (!que.empty())
    {
        TreeNode *q = que.front();
        cout << q->val << ", ";
        que.pop();

        if (q->left != nullptr)
        {
            que.push(q->left);
        }

        if (q->right != nullptr)
        {
            que.push(q->right);
        }
    }

    cout << endl;
}

TreeNode *recoverFromPreorder(string S)
{
    stack<TreeNode *> path;
    int pos = 0;
    while (pos < S.size())
    {
        int level = 0;
        while (S[pos] == '-')
        {
            ++level;
            ++pos;
        }
        int value = 0;
        while (pos < S.size() && isdigit(S[pos]))
        {
            value = value * 10 + (S[pos] - '0');
            ++pos;
        }
        TreeNode *node = new TreeNode(value);
        if (level == path.size())
        {
            if (!path.empty())
            {
                path.top()->left = node;
            }
        }
        else
        {
            while (level != path.size())
            {
                path.pop();
            }
            path.top()->right = node;
        }
        path.push(node);
    }
    while (path.size() > 1)
    {
        path.pop();
    }
    return path.top();
}

int main()
{
    string str = "1-2--3--4-5--6--7";

    TreeNode *res = recoverFromPreorder(str);

    printTree(res);
}