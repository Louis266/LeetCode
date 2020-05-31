#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool check(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
}

bool isSymmetric(TreeNode *root)
{
    return check(root, root);
}

int main()
{
}