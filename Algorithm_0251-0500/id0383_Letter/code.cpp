#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    /*
    map<char, int> m;
    for (char i : magazine)
    {
        m[i] += 1;
    }

    for (char i : ransomNote)
    {
        if (m[i] == 0)
            return false;
        if (m[i] > 0)
            m[i] -= 1;
    }

    return true;
    */

    vector<int> v(26);
    for (char i : magazine)
    {
        v[(i - 'a')] += 1;
    }
    for (char i : ransomNote)
    {
        if (v[(i-'a')] == 0)
            return false;
        if (v[(i-'a')] > 0)
            v[(i-'a')] -= 1;
    }
    return true;
}

int main()
{
    string a = "aa";
    string b = "ab";
    cout << canConstruct(a, b) << endl;
}