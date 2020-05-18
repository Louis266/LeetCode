#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int maxProduct(vector<int> &nums)
{
    vector<int> maxF(nums), minF(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
        minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
    }

    return *max_element(maxF.begin(), maxF.end());
}

int main()
{
    vector<int> vec_1 = {2, 3, -2, 4};

    cout << maxProduct(vec_1) << endl;
}
