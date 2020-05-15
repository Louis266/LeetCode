#include <vector>
#include <iostream>
#include <map>

using namespace std;

int singleNumber(vector<int> &nums)
{
    map<int, int> m;

    for (int i = 0; i < nums.size(); i++)
    {
        if (m[nums[i]])
        {
            m[nums[i]] += 1;
        }
        else
        {
            m[nums[i]] = 1;
        }
    }

    for (map<int, int>::iterator i = m.begin(); i != m.end(); i++)
    {
        if (i->second == 1)
        {
            return i->first;
        }
    }
    cout << "no single value found";
    return 0;
}
int main()
{
    int n[3] = {2, 2, 1};
    vector<int> nums(n, n + 3);

    cout << singleNumber(nums);
}