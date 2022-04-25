#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int> path;

void backtracking(int targetSum, int k, int sum, int startIndex)
{

    if (sum > targetSum)
    {
        return;
    }
    
    if (path.size() == k)
    {
        if (sum == targetSum)
        {
            res.push_back(path);
            // path.pop_back();
        }
        return;
    }

    for (int i = startIndex; i <= 9 - (k-path.size()); i++)
    {
        sum += i;
        path.push_back(i);
        backtracking(targetSum, k, sum, i + 1);
        sum -= i;
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    res.clear();
    path.clear();
    backtracking(n, k, 0, 1);
    return res;

}