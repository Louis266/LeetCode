#include <vector>
#include <iostream>

using namespace std;

int wiggleMaxLength(vector<int> &nums)
{
    if (nums.size() <= 1) return nums.size();
    int curDiff = 0;
    int preDiff = 0;
    int res = 1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        curDiff = nums[i+1] - nums[i];
        if ((curDiff > 0 && preDiff <=0) || (preDiff >= 0 && curDiff < 0))
        {
            res++;
            preDiff = curDiff;
        }
        
    }
    return res;
}

int main()
{
    vector<int> a = {1, 7, 4, 9, 2, 5};
    vector<int> b = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    vector<int> c = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> d = {65};
    vector<int> e = {1, 2};
    vector<int> f = {0, 0, 0};

    cout << wiggleMaxLength(a) << '\t' << wiggleMaxLength(b) << '\t' << wiggleMaxLength(c) << endl;
    cout << wiggleMaxLength(d) << '\t' << wiggleMaxLength(e) << '\t' << wiggleMaxLength(f) << endl;
}