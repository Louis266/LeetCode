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

TreeNode* traversal (vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int> preorder, int preorderBegin, int preorderEnd)
{
    if (preorderBegin == preorderEnd) return NULL;
    
    int rootValue = preorder[preorderBegin];
    TreeNode* root = new TreeNode(rootValue);

    if (preorderEnd - preorderBegin == 1) return root; 
    int delimiterIndex;
    for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++)
    {
        if (inorder[delimiterIndex] == rootValue) break;
    }
    int leftInorderBegin = inorderBegin;
    int leftInorderEnd = delimiterIndex;

    int rightInorderBegin = delimiterIndex + 1;
    int rightInorderEnd = inorderEnd;

    int lefPreorderBegin = preorderBegin + 1;
    int leftPreorderEnd = preorderBegin + 1 + delimiterIndex - inorderBegin;

    int rightPreorderBegin = preorderBegin + 1 + (delimiterIndex - inorderBegin) + 1;
    int rightPreorderEnd = preorderEnd;

    root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, preorder, lefPreorderBegin, leftPreorderEnd);
    root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, preorder, rightPreorderBegin, rightPreorderEnd);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    if (preorder.size() == 0 || inorder.size() == 0)
        return NULL;
    
    return traversal(inorder, 0, inorder.size(), preorder, 0, preorder.size());
    
}
/*
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
*/

int main()
{
    vector<int> pre_1 = {3, 9, 20, 15, 7};
    vector<int> in_1 = {9, 3, 15, 20, 7};

    TreeNode *t = buildTree(pre_1, in_1);

    //print_tree(t);
}