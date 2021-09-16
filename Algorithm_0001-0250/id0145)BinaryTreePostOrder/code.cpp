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

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> post;
    if (root == nullptr)
        return post;
    vector<int> left = postorderTraversal(root->left);
    post.insert(post.end(), left.begin(), left.end());
    vector<int> right = postorderTraversal(root->right);
    post.insert(post.end(), right.begin(), right.end());

    post.push_back(root->val);

    return post;
}