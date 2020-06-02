#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int rob(vector<int> &nums)
{
    int length = nums.size();
    if (length == 0)
        return 0;
    if (length == 1)
        return nums[0];
    vector<int> dp(length + 1);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < length - 1; i++)
    {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    int result = dp[length - 2];
    dp[0] = 0;
    dp[1] = nums[1];
    for (int i = 2; i < length; i++)
    {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    result = max(result, dp[length - 1]);
    return result;
}

int main()
{
}