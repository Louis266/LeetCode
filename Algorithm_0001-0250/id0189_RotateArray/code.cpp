#include <iostream>
#include <vector>

using namespace std;

void preRotate(vector<int> &nums, int head, int tail)
{

    while (head <= tail)
    {
        int temp = nums[head];

        nums[head] = nums[tail];
        nums[tail] = temp;

        head++;
        tail--;
    }
}

void rotate(vector<int> &nums, int k)
{
    int head = 0;
    int tail = nums.size() - k - 1;

    preRotate(nums, head, tail);

    head = nums.size() - k;
    tail = nums.size() - 1;

    preRotate(nums, head, tail);

    head = 0;
    tail = nums.size() - 1;

    preRotate(nums, head, tail);
}

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);

    rotate(a, 3);

    for(int i = 0; i < a.size(); i ++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    
}