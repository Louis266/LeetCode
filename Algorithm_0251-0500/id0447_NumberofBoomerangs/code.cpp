#include <vector>
#include <unordered_map>

using namespace std;
/*
float distance (vector<int> &a, vector<int> &b)
{
    return ((a[0] - b[0])^2 + (a[1] - b[1])^2)^(0.5);
}*/

int numberOfBoomerangs(vector<vector<int> > &points)
{
    int ans = 0;
    for (auto &p : points)
    {
        unordered_map<int, int> cnt;
        for (auto &q : points)
        {
            int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
            ++cnt[dis];
        }
        for (auto &[_, m] : cnt)
        {
            ans += m * (m - 1);
        }
    }
    return ans;
}