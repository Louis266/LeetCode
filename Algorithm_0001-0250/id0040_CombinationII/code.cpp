#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
vector<int> path;

void backtracking(vector<int> &candidate, int target, int sum, int startIndex, vector<bool> &used)
{
    if (sum == target)
    {
        res.push_back(path);
        return;
    }
    for (int i = startIndex; i < candidate.size() && sum + candidate[i] <= target; i++)
    {
        if (i > 0 && candidate[i] == candidate[i - 1] && used[i - 1] == false)
        {
            continue;
        }
        sum += candidate[i];
        path.push_back(candidate[i]);
        used[i] = true;
        backtracking(candidate, target, sum, i + 1, used);
        used[i] = false;
        sum -= candidate[i];
        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<bool> used(candidates.size(), false);
    path.clear();
    res.clear();
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0, used);
    return res;
}