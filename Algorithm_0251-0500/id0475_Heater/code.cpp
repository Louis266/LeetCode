#include <vector>
#include <algorithm>

using namespace std;

int findRadius(vector<int> &houses, vector<int> &heaters)
{
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int ans = 0;
    for (int i = 0, j = 0; i < houses.size(); i++)
    {
        int curDistance = abs(houses[i] - heaters[j]);
        while (j < heaters.size() - 1 && abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1]))
        {
            j++;
            curDistance = min(curDistance, abs(houses[i] - heaters[j]));
        }
        ans = max(ans, curDistance);
    }
    return ans;
}
