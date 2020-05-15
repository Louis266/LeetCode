#include <string>
#include <iostream>
#include <map>

using namespace std;

int longestPalindrome(string s)
{
    map<char, int> m;

    for (int i = 0; i < s.size(); i++)
    {
        if (!m[s[i]])
        {
            m[s[i]] = 0;
        }

        m[s[i]] += 1;
    }

    int count = 0;
    int single_count = 0;
    for (map<char, int>::iterator i = m.begin(); i != m.end(); i++)
    {
        if (i->second % 2 == 0 && i->second != 0)
        {
            count += i->second;
        }
        else
        {
            single_count++;
            count += i->second - 1;
        }
    }

    if (single_count!=0)
    {
        count += 1;
    }
    
    return count;
}

int main()
{
    string s = "abccccdd";

    cout << longestPalindrome(s) << endl;
}
