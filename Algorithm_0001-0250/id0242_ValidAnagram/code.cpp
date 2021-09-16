#include <string>
#include <vector>

using namespace std;

bool isAnagram(string s, string t)
{
    vector<int> v(26);   
    for (char i: s)
    {
        v[i-'a']+=1;
    }

    if (s.size()!=t.size()) return false;

    for (char i: t)
    {
        if (v[i-'a'] == 0) return false;
        if (v[i-'a'] > 0) v[i-'a'] -=1;
    }
    
    return true;
}

