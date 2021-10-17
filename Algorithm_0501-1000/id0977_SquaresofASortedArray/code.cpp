#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    int start = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0 && nums[i + 1] >= 0)
        {
            start = i + 1;
        }
    }

    vector<int> res;
    int i = nums[start]*nums[start];
    res.push_back(i);
    int head = start-1;
    int tail = start+1;

    while (head >= 0 || tail <= nums.size()-1)
    {
        if (0-nums[head] > nums[tail])
        {
            int i = nums[tail]* nums[tail];
            res.push_back(i);
            tail++;
        }
        else
        {
            int i = nums[head] * nums[head];
            res.push_back(i);
            head--;
        }
        
        
    }
    while (head>=0)
    {
        for (int i = head; i >= 0; i--)
        {
            int j = nums[i]*nums[i];
            res.push_back(j);
        }
        
    }
    while (tail < nums.size())
    {
        for (int i = tail; i < nums.size(); i++)
        {
            int j = nums[i] * nums[i];
            res.push_back(j);
        }
    }
    
    
    
    
    return res;
}

int main(){

    vector<int> a;
    a.push_back(-4);
    a.push_back(-1);
    a.push_back(0);
    a.push_back(3);
    a.push_back(10);

    vector<int> b = sortedSquares(a);

    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << '\t';
    }
    cout << endl;
    
}