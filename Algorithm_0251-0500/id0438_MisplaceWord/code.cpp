#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
    vector<int> res;
    vector<int> temp(26, 0);

    if (s.length() < p.length())
        return res;
    if (p.length() == 0)
        return res;
    vector<int> alphabet(26, 0);

    for (int i = 0; i < p.size(); i++)
    {
        alphabet[p[i] - 'a'] += 1;
        //cout << p[i] - 'a' << endl;
    }

    int frac_count = p.size();
    int tail = 0 + frac_count - 1;
    int head = 0;

    for (int i = 0; i < frac_count; i++)
    {
        temp[s[i] - 'a'] += 1;
    }

    while (tail < s.size() - 1)
    {
        if (temp == alphabet)
        {
            res.push_back(head);
        }

        temp[s[head++] - 'a'] -= 1;
        temp[s[++tail] - 'a'] += 1;

        //cout << s[head] << endl;
    }
    if (temp == alphabet)
    {
        res.push_back(head);
    }

    return res;
}

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> res = findAnagrams(s, p);

    cout << '[';
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    cout << ']' << endl;
}