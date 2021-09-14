#include <vector>

using namespace std;

int search(vector<int> &nums, int target)
{
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo <= hi)
    {
        int middle = (hi - lo) / 2;

        if (nums[middle] > target)
            hi = middle - 1;
        if (nums[middle] < target)
            lo = middle + 1;
        if (nums[middle] == target)
            return middle;
    }

    return -1;
}