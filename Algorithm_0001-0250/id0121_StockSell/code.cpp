#include <vector>
#include <iostream>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int max = 0;
    int begin = 0;

    for (int i = 0; i < prices.size() - 1; i++)
    {
        if (prices[i + 1] <= prices[i])
        {
            if (prices[begin] > prices[i + 1])
            {
                begin = i + 1;
            }
        }

        if (prices[i + 1] > prices[i])
        {
            if (max < prices[i + 1] - prices[begin])
            {
                max = prices[i + 1] - prices[begin];
            }
        }
    }

    return max;
}

int main()
{
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(1);
    //nums.push_back(4);

    cout << maxProfit(nums) << endl;
}