#include <vector>

using namespace std;

int candy(vector<int> &ratings)
{
    vector<int> res(ratings.size(), 1);

    for (int i = 1; i < res.size(); i++)
    {
        if (ratings[i] > ratings[i - 1])
            res[i] = res[i - 1] + 1;
    }
    for (int i = res.size() - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
            res[i] = max(res[i], res[i + 1] + 1);
    }
    int resnum = 0;
    for (int i = 0; i < res.size(); i++)
    {
        resnum += res[i]; 
    }

    return resnum;
    
}