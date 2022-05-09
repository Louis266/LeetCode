#include <bits/stdc++.h>

using namespace std;

int findRepeatNumber(vector<int> &nums)
{
    vector<int> n(nums.size(),0);

    for (int i = 0; i < nums.size(); i++)
    {
        if (n[nums[i]] == 0) n[nums[i]] = 1;
        else if (n[nums[i]] == 1) return nums[i];
    }
    return -1;
    
}