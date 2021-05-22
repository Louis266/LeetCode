#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;

    vector<string> rows(min(numRows, int(s.size())));

    int curRow = 0;
    bool goingDOwn = false;

    for (char c : s)
    {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows - 1)
            goingDOwn = !goingDOwn;
        curRow += goingDOwn ? 1 : -1;
    }

    string res;

    for (string row : rows)
        res += row;

    return res;
}

string convert_row(string s, int numRows)
{

    if (numRows == 1)
        return s;

    string ret;
    int n = s.size();
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j + i < n; j += cycleLen)
        {
            ret += s[j + i];
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                ret += s[j + cycleLen - i];
        }
    }
    return ret;
}
