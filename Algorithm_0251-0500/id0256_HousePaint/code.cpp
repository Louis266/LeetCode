#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int minCost(vector<vector<int> > &costs)
{
    for (int i = costs.size() - 2; i >= 0; i--)
    {
        costs[i][0] += min(costs[i + 1][1], costs[i + 1][2]);
        costs[i][1] += min(costs[i + 1][0], costs[i + 1][2]);
        costs[i][2] += min(costs[i + 1][0], costs[i + 1][1]);
    }
    if (costs.size() == 0)
    {
        return 0;
    }
    return min(costs[0][0], min(costs[0][1], costs[0][2]));
}

int main()
{
    int a[3] = {17, 2, 17};
    int b[3] = {16, 16, 5};
    int c[3] = {14, 3, 19};
    vector<vector<int> > vec;
    vector<int> aa(a, a + 3);
    vector<int> bb(b, b + 3);
    vector<int> cc(c, c + 3);

    vec.push_back(aa);
    vec.push_back(bb);
    vec.push_back(cc);

    cout << minCost(vec);
}