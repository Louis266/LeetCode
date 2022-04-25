#include <bits/stdc++.h>

using namespace std;

string replaceSpace(string s)
{
    string res;
    for (char i : s)
    {
        if (i == ' ')
            res.append("\%20");
        else
            res.push_back(i);
    }
    return res;
}