#include <vector>
#include <iostream>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            return i;
        }

        if (nums[i] > target)
        {
            return i;
        }
    }
    return nums.size();
}

int main()
{
    vector<int> v = {1, 3, 5, 6};
    int t1 = 5;
    int t2 = 2;
    int t3 = 7;
    int t4 = 0;
    cout << searchInsert(v, t1) << endl;
    cout << searchInsert(v, t2) << endl;
    cout << searchInsert(v, t3) << endl;
    cout << searchInsert(v, t4) << endl;
}
