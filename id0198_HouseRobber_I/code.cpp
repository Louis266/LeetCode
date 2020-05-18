#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int rob(vector<int> &nums)
{
    int c_max = 0;
    int pre = 0;

    for (int i:nums)
    {
        int temp = c_max;
        c_max = max(pre+i, c_max);
        pre = temp;
    }
    
    return c_max;
}

int main()
{
    vector<int> houses_1 = {2,7,9,3,1};
    cout << rob(houses_1) << endl;
}
