#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<string>> res;

vector<string> path;

bool isPalindrome(const string &s, int start, int end)
{
    for (int i = start, j = end; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }
    return true;
}

void backtracking(int startIndex, const string &s)
{
    if (startIndex >= s.size())
    {
        res.push_back(path);
        return;
    }
    for (int i = startIndex; i < s.size(); i++)
    {
        if (isPalindrome(s, startIndex, i))
        {
            string str = s.substr(startIndex, i - startIndex + 1);
            path.push_back(str);
        }
        else {
            continue;
        }
        backtracking(i+1, s);
        path.pop_back();
    }
}

vector<vector<string>> partition(string s)
{
    res.clear();
    path.clear();
    backtracking(0, s);
    return res;
}