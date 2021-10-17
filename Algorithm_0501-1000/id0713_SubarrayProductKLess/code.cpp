#include <vector>
#include <iostream>

using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0] < k ? 1 : 0;

    int res = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        res += nums[i] < k ? 1 : 0;
    }

    int head = 0, tail = 1;

    while (head < tail && tail < nums.size())
    {
        int x = 1;

        for (int i = head; i <= tail; i++)
        {
            x*=nums[i];
        }
        
        if (x < k)
        {
            cout << nums[head] << ' ' << nums[tail] << endl;
            res++;
            tail++;
        }
        else
        {
            head++;
        }
    }
    
    while (head < tail)
    {
        int x = 1;

        for (int i = head; i <= tail; i++)
        {
            x*=nums[i];
        }
        if (x < k)
        {
            cout << nums[head] << ' ' << nums[tail] << endl;
            res++;
        }
        head++;
    }

    return res;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    //nums.push_back(6);

    cout << numSubarrayProductLessThanK(nums, 0) << endl;
}