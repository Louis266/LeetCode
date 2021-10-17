#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    TreeNode *root;
    if (root1 != nullptr && root2 != nullptr)
    {
        root->val = root1->val + root2->val;
    }
    else if (root1 == nullptr && root2 != nullptr)
    {
        root->val = root2->val;
    }
    else if (root1 != nullptr && root2 == nullptr)
    {
        root->val = root1->val;
    }

    root->right = mergeTrees(root1->right, root2->right);
    root->left = mergeTrees(root1->left, root2->left);

    return root;
}

int main()
{
    TreeNode *r1;
    TreeNode *r2;
}