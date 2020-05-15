#include <vector>
#include <iostream>

using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j >= 0; j--)
        {
            sum += nums[j];
            if (sum == k)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    vector<int> vec_1 = {1, 2, 3, 4, 5, 6};
    int target_1 = 10;

    cout << subarraySum(vec_1, target_1) << endl;
}