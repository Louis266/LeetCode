#include <vector>
#include <iostream>

using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    vector<bool> res;

    int max = 0;

    for (int i = 0; i < candies.size(); i++)
    {
        if (candies[i] > max)
            max = candies[i];
    }

    for (int i = 0; i < candies.size(); i++)
    {
        if (max - candies[i] > extraCandies)
        {
            res.push_back(false);
        }
        else
        {
            res.push_back(true);
        }
    }
    return res;
}

int main()
{
    int can[5] = {2,3,5,1,3};

    vector<int> c (begin(can),end(can));

    int extra = 3;

    vector<bool> r = kidsWithCandies(c, extra);

    for (int i = 0; i < r.size(); i++)
    {
        cout << r[i] << " ";
    }

    cout <<endl;
    
}