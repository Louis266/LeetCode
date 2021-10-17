#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum >= target)
            {
                ans = min(ans, j - i + 1);
                break;
            }
        }
    }
    return ans == INT_MAX ? 0 : ans;
}