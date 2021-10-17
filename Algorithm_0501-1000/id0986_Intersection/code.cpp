#include <vector>

using namespace std;

vector<vector<int> > intervalIntersection(vector<vector<int> > &firstList, vector<vector<int> > &secondList)
{

    vector<vector<int> > res;
    int n1 = firstList.size();
    int n2 = secondList.size();
    if (n1 == 0 || n2 == 0)
    {
        return res;
    }

    // 两个数组的指针
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2)
    {
        int start = max(firstList[i][0], secondList[j][0]);
        int end = min(firstList[i][1], secondList[j][1]);
        // 注意这里是小于等于，因为[5,5]也是有效的区间，虽然只有一个元素
        if (start <= end)
        {
            res.push_back({start, end});
        }
        // 按照判断去遍历下一个
        firstList[i][1] < secondList[j][1] ? ++i : ++j;
    }

    return res;
}