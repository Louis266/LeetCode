#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*
int strStr(string haystack, string needle)
{
    if (!needle.size())
        return 0;
    if (!haystack.size())
        return -1;
    //先构造pattern
    int j = -1, i = 0; //j在后面，i在前面
    vector<int> b(needle.size() + 1);
    b[i] = j;
    while (i < needle.size())
    {
        while (j >= 0 && needle[i] != needle[j])
            j = b[j];
        i++, j++;
        b[i] = j;
    }

    j = 0, i = 0; //j这回是text的， i是pattern的
    while (j < haystack.size())
    {
        while (i >= 0 && needle[i] != haystack[j])
            i = b[i];
        i++, j++;
        if (i == needle.size())
        {
            return j - needle.size();
        }
    }
    return -1;
}
*/

void getNext(int *next, const string &s)
{
    int j = -1;
    next[0] = j;

    for (int i = 1; i < s.size(); i++)
    {
        while (j >= 0 && s[i] != s[j + 1])
        {
            j = next[j];
        }

        if (s[i] == s[j + 1])
        {
            j++;
        }

        next[i] = j;
    }
}

int strStr(string haystack, string needle)
{
    if (needle.size() == 0)
    {
        return 0;
    }

    int next[needle.size()];
    getNext(next, needle);

    int j = -1;

    for (int i = 0; i < haystack.size(); i++)
    {
        while (j >= 0 && haystack[i] != needle[j + 1])
        {
            j = next[j];
        }

        if (haystack[i] == needle[j + 1])
        {
            j++;
        }

        if (j == (needle.size() - 1))
        {
            return (i - needle.size() + 1);
        }
    }

    return -1;
}
int main()
{
    string haystack = "hello";
    string needle = "ll";

    // cout << strStr(haystack, needle) << endl;
}