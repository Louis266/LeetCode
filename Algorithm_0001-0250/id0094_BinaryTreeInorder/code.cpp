#include <vector>

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

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> in;
    if (root == nullptr)
        return in;
    vector<int> left = inorderTraversal(root->left);
    in.insert(in.end(), left.begin(), left.end());
    in.push_back(root->val);
    vector<int> right = inorderTraversal(root->right);
    in.insert(in.end(), right.begin(), right.end());

    return in;
}