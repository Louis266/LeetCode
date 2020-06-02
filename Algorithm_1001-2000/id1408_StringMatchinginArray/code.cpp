#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> stringMatching(vector<string> &words)
{
    vector<string> res;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            if (words[i].size() < words[j].size() && words[j].find(words[i]) != string::npos)
            {
                res.push_back(words[i]);
                break;
            }
        }
    }
    return res;
}

int main()
{
    vector<string> vec = {"mass", "as", "hero", "superhero"};

    vector<string> result = stringMatching(vec);

    for (string s : result)
    {
        cout << s << endl;
    }
}