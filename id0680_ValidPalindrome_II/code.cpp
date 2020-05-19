#include <string>
#include <iostream>

using namespace std;

bool checkPalindrome(const string &s, int low, int high)
{
    for (int i = low, j = high; i < j; ++i, --j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }
    return true;
}

bool validPalindrome(string s)
{
    int low = 0, high = s.size() - 1;
    while (low < high)
    {
        char c1 = s[low], c2 = s[high];
        if (c1 == c2)
        {
            ++low;
            --high;
        }
        else
        {
            return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
        }
    }
    return true;
}

int main()
{
    string s1 = "aabbaa";

    string s2 = "aadbbaa";

    if (validPalindrome(s1))
    {
        cout << "s1 ok" << endl;
    }
    
    if (validPalindrome(s2))
    {
        cout << "s2 ok" << endl;
    }
}