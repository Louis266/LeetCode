#include <vector>
#include <algorithm>

using namespace std;

static bool cmp (const vector<int>& a, const vector<int>& b)
{
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    vector<vector<int>> res;
    if (intervals.size() == 0) return res;

    sort(intervals.begin(), intervals.end(), cmp);
    bool flag = false;
    int len = intervals.size();

    for (int i = 1; i < len; i++)
    {
        int start = intervals[i-1][0];
        int end = intervals[i - 1][1];

        while (i < len && intervals[i][0] <= end)
        {
            end = max(end, intervals[i][1]);
            if (i == len - 1) flag = true;
            i++;
        }
        res.push_back({start, end});
        
    }
    if (flag == false)
    {
        res.push_back({intervals[len - 1][0], intervals[len-1][1]});
    }
    return res;
}