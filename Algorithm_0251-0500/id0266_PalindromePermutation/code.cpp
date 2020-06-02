#include <string>
#include <iostream>
#include <map>

using namespace std;

bool canPermutePalindrome(string s)
{
    map<char, int> data;

    for (char c : s)
    {
        map<char, int>::iterator it = data.find(c);
        if (it == data.end())
        {
            data.insert(map<char, int>::value_type(c, 1));
        }
        else
        {
            it->second += 1;
        }
    }

    int flag = 0;
    for (auto it : data)
    {
        if (it.second % 2 == 1)
        {
            if (flag == 1)
            {
                return false;
            }
            else
            {
                flag++;
            }
        }
    }
    return true;
}

int main()
{
    string s1 = "abba";

    string s2 = "abbadkdonmgohhha";

    string s3 = "asdfghjklkjhgfdsa";

    string s4 = "heismart";

    if (canPermutePalindrome(s1))
    {
        cout << "s1 has" << endl;
    }
    if (canPermutePalindrome(s2))
    {
        cout << "s2 has" << endl;
    }
    if (canPermutePalindrome(s3))
    {
        cout << "s3 has" << endl;
    }
    if (canPermutePalindrome(s4))
    {
        cout << "s4 has" << endl;
    }
}