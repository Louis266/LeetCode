#include <string>
#include <vector>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int length = 0;

    int pos = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int flag = 0;
        for (int j = pos; j < i; j++)
        {
            if (s[i] == s[j])
            {
                if (i - j > length)
                {
                    length = i - j;
                }

                pos = j + 1;
                flag = 1;

                cout << " do found:" << '\t' << i << '\t';
                cout << pos << '\t';
                cout << length << endl;
                break;
            }
        }
        if (!flag)
        {
            if (i == pos)
            {
                length = 1;
            }

            if (i - pos +1 > length)
            {
                length = i - pos + 1;
                //cout << "test\n";
            }

            cout << "not found:" << '\t' << i << '\t';
            cout << pos << '\t';
            cout << length << endl;
        }
    }

    return length;
}

int main()
{
    string s_0 = "abcabcbb";
    string s_1 = "bbbbb";
    string s_2 = "pwwkew";

    string s_3 = "asdfghjkkkkjhl";

    cout << "length of the logest str: \n"
         << lengthOfLongestSubstring(s_0) << endl;
    cout << "=======================================" << endl;

    cout << "length of the logest str: \n"
         << lengthOfLongestSubstring(s_1) << endl;
    cout << "=======================================" << endl;

    cout << "length of the logest str: \n"
         << lengthOfLongestSubstring(s_2) << endl;
    cout << "=======================================" << endl;

    cout << "length of the logest str: \n"
         << lengthOfLongestSubstring(s_3) << endl;
    cout << "=======================================" << endl;
}