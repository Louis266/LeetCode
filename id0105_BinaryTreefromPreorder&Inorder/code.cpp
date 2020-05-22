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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    
    if (preorder.size() == 0)
    {
        return NULL;
    }
    
    int val = preorder[0];

    //cout << val << endl;

    TreeNode* root = new TreeNode(val);

    vector<int> left_pre;
    vector<int> left_in;

    vector<int> right_pre;
    vector<int> right_in;

    int root_pre;
    int flag = 0;
    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] != val && !flag)
        {
            left_in.push_back(inorder[i]);
        }

        if (inorder[i] == val)
        {
            root_pre = i;
            flag = 1;
        }

        if (inorder[i] != val && flag)
        {
            right_in.push_back(inorder[i]);
        }
    }

    for (int i = 1; i <= left_in.size(); i++)
    {
        left_pre.push_back(preorder[i]);
    }

    for (int i = left_in.size() + 1; i < preorder.size(); i++)
    {
        right_pre.push_back(preorder[i]);
    }

    root->right = buildTree(right_pre, right_in);
    
    root->left = buildTree(left_pre, left_in);
    return root;
}

void print_tree(TreeNode *t)
{
    if (t==NULL)
    {
        return;
    }
    
    cout << t->val << endl;
    cout << "/" << endl;
    print_tree(t->left);
    cout << "=" << endl;
    print_tree(t->right);
}

int main()
{
    vector<int> pre_1 = {3, 9, 20, 15, 7};
    vector<int> in_1 = {9, 3, 15, 20, 7};

    TreeNode *t = buildTree(pre_1, in_1);

    print_tree(t);
}