#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int> path;

void backtracking(vector<int> &candidate, int target, int sum, int startIndex)
{
    if (sum > target)
    {
        return;
    }
    if (sum == target)
    {
        res.push_back(path);
        return;
    }
    for (int i = startIndex; i < candidate.size(); i++)
    {
        sum += candidate[i];
        path.push_back(candidate[i]);
        backtracking(candidate, target, sum, i);
        sum -= candidate[i];
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    res.clear();
    path.clear();

    backtracking(candidates, target, 0, 0);

    return res;
}