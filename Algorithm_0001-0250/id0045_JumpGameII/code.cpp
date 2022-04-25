#include <vector>
#include <iostream>

using namespace std;

int jump(vector<int> &nums)
{
    int tempPos = nums.size() - 1;

    int tempSize = nums.size();

    int res = 0;
    while (tempSize > 1)
    {
        for (int i = 1; tempSize - i >= 1; i++)
        {
            if (nums[tempSize - i - 1] >= i)
            {
                tempPos = tempSize - i - 1;
            }
        }

        tempSize = tempPos + 1;

        res += 1;
    }

    return res;
}

int main()
{
    vector<int> nums = {2,3,0,1,4};

    cout << jump(nums) << endl;
}