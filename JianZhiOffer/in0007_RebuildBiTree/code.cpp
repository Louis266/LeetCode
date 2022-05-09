#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printVec(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ' ';
    }
    cout << endl;
    
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.size() == 0) return NULL;
    int r = preorder[0];
    //root->val = r;
    TreeNode *root = new TreeNode(r);
    if (preorder.size() == 1)
    {
        return root;
    }

    int n;

    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == r)
            n = i;
    }

    vector<int> pre_left(preorder.begin()+1, preorder.begin()+n+1);
    vector<int> in_left(inorder.begin(), inorder.begin()+n);
    vector<int> pre_right(preorder.begin()+n+1, preorder.end());
    vector<int> in_right(inorder.begin()+n+1, inorder.end());

    printVec(pre_left);
    printVec(in_left);
    printVec(pre_right);
    printVec(in_right);

    cout << "==========================================" << endl;
    root->left = buildTree(pre_left, in_left);
    root->right = buildTree(pre_right, in_right);

    return root;
}


int main()
{
    vector<int> pre = {3,9,20,15,7};
    vector<int> in = {9,3,15,20,7};

    TreeNode* res = buildTree(pre, in);

}