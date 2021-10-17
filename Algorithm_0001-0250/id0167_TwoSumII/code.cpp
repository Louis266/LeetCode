#include <vector>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int i = 0;
    int j = numbers.size() - 1;

    while (i <= j)
    {
        if (numbers[i] + numbers[j] > target)
        {
            j--;
        }
        if (numbers[i] + numbers[j] < target){
            i++;
        }
        if (numbers[i] + numbers[j] == target)
        {
            vector<int> res;
            res.push_back(i);
            res.push_back(j);

            return res;
        }
    }
    
}