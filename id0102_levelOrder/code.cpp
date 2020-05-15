#include <vector>
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

vector<vector<int> > levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);

    vector<vector<int> > result;

    while (q.size() != 0)
    {
        int size = q.size();
        vector<int> level;

        while (size--)
        {
            TreeNode *node = q.front();
            q.pop();

            if (!node)
            {
                continue;
            }

            level.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        }

        if (level.size() != 0)
        {
            result.push_back(level);
        }
    }
    return result;
}

int main()
{
    TreeNode root(10);
    TreeNode n1(12);
    TreeNode n2(13);
    TreeNode n3(6);
    TreeNode n4(9);

    root.left = &n1;
    root.right = &n2;
    n1.left = &n3;
    n1.right = &n4;

    vector<vector<int> > r = levelOrder(&root);

    for (int i = 0; i < r.size(); i++)
    {
        cout << "[ " << endl;
        cout << "\t" << "[";
        for (int j = 0; j < r[i].size(); j++)
        {
            cout << r[i][j] << ", ";     
        }
        cout << "]" << endl;
        cout << "]" << endl;
    }
}