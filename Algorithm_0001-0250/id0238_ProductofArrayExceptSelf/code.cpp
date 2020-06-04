#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int length = nums.size();

    vector<int> L(length, 0);
    vector<int> R(length, 0);
    vector<int> res(length);

    L[0] = 1;

    for (int i = 1; i < length; i++)
    {
        L[i] = L[i - 1] * nums[i - 1];
    }

    R[length - 1] = 1;

    for (int i = length - 2; i >= 0; i--)
    {
        R[i] = R[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < length; i++)
    {
        res[i] = L[i] * R[i];
    }

    return res;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4};

    vector<int> res = productExceptSelf(vec);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}