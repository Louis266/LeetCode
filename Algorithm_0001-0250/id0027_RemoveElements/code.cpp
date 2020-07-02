#include <vector>
#include <iostream>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == val)
        {
            for (int j = i; j < size - 1; j++)
            {
                nums[j] = nums[j+1];
            }
            size--;
            i--;
        }
        
    }

    int rest = nums.size() - size;

    for (int i = 0; i < rest; i++)
    {
        nums.pop_back();
    }
    
    return nums.size();
    
}

int main()
{
    vector<int> nums = {3,2,2,3};
    int val = 3;

    cout << removeElement(nums, val) << endl;

    for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
    {
        cout << *i << "->";
    }

    cout << endl;
    
}
