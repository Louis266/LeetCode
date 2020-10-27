#include <iostream>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> pre;
    if (root == nullptr)
        return pre;    
    pre.push_back(root->val);
    vector<int> left = preorderTraversal(root->left);
    pre.insert(pre.end(), left.begin(), left.end());
    vector<int> right = preorderTraversal(root->right);
    pre.insert(pre.end(), right.begin(), right.end());

    return pre;
}

void printVector(vector<int> vec)
{
    for (vector<int>::iterator i = vec.begin(); i!= vec.end(); i++)
    {
        cout << *i << ' ';
    }
    cout << endl;
    
}

int main(){
    TreeNode a;
    TreeNode b;
    TreeNode c;
    a.val = 1;
    b.val = 2;
    c.val = 3;
    a.right = &b;
    b.left = &c;

    vector<int> res = preorderTraversal(&a);

    printVector(res);
    
}