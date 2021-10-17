#include <string>

using namespace std;

void reverse(string &s, int i, int j)
{
    while (i <= j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    
}

string reverseWords(string s)
{
    int begin = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            reverse(s,begin, i - 1);

            begin = i+1;
        }
        if (i == s.size() - 1)
        {
            reverse(s, begin, i);
        }
        
    }

    return s;
    
    
}