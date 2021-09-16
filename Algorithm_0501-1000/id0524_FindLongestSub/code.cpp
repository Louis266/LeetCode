#include <vector>
#include <string>

using namespace std;

string findLongestWord(string s, vector<string> &dictionary)
{
    string res;
    for (string d : dictionary)
    {
        int j = 0;
        for (int i = 0; i < s.size() && j < d.size(); i++)
        {
            if (d[j] == s[i])
            {
                j++;
            }
        }
        if (j == d.size())
        { //当d全部遍历完，才可以判断是否将d存入ans;
            if (d.size() > res.size())
            { //当d.size()>ans.size(),ans=d;
                res = d;
            }
            else if (d.size() == res.size())
            { //当d.size()==ans.size(),ans=d<ans?d:ans;
                res = d < res ? d : res;
            }
        }
    }

    return res;
}