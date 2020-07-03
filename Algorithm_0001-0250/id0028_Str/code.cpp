#include <string>
#include <iostream>
#include <vector>

using namespace std;

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

int main()
{
    string haystack = "hello";
    string needle = "ll";

    cout << strStr(haystack, needle) << endl;
}