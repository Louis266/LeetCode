#include <vector>

using namespace std;

bool lemonadeChange(vector<int> &bills)
{
    int five_count = 0;
    int ten_count = 0;
    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
        {
            five_count++;
        }
        if (bills[i] == 10)
        {
            if (--five_count < 0)
            {
                return false;
            }
            ten_count++;
        }
        if (bills[i] == 20)
        {
            if (--ten_count < 0)
            {
                ++ten_count;
                five_count -= 3;
                if (five_count < 0)
                {
                    return false;
                }
            }
            else if (--five_count < 0)
            {
                return false;
            }
        }
    }
    return true;
}