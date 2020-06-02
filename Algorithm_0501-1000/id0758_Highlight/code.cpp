#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

string boldWords(vector<string> &words, string S)
{
    int flag[501];
    for (int i = 0; i < 501; i++)
    {
        flag[i] = 0;
    }
    for (vector<string>::iterator it = words.begin(); it != words.end(); it++)
    {
        size_t f = S.find(*it);
        while (f != string::npos)
        {
            int po = (int)f;
            for (int i = po; i < po + (*it).size(); i++)
            {
                flag[i] = 1;
            }

            f = S.find(*it, f + 1);
        }
    }

    for (int i = 0; i < S.size(); i++)
    {
        cout << flag[i] << "\t";
    }
    cout << endl;

    string result = "";

    if (flag[0] == 1)
    {
        result.append("<b>");
    }
    result.push_back(S[0]);
    if (flag[0] == 1 && flag[1] == 0)
    {
        result.append("</b>");
    }

    for (int i = 1; i < S.size(); i++)
    {
        if (flag[i] == 1 && flag[i - 1] == 0)
        {
            result.append("<b>");
        }
        result.push_back(S[i]);
        if (flag[i] == 1 && flag[i + 1] == 0)
        {
            result.append("</b>");
        }
    }

    return result;
}

void test_1()
{
    string word_1 = "book";
    string word_2 = "big";
    string word_3 = "ok";
    string word_4 = "bigger";

    vector<string> words;
    words.push_back(word_1);
    words.push_back(word_2);
    words.push_back(word_3);
    words.push_back(word_4);

    string s = "bookbigger";

    cout << boldWords(words, s) << endl;
}

void test_2()
{
    string word_1 = "hello";
    string word_2 = "bye";
    string word_3 = "ok";

    vector<string> words;
    words.push_back(word_1);
    words.push_back(word_2);
    words.push_back(word_3);

    string s = "hellohibyeokornot";

    cout << boldWords(words, s) << endl;
}

void test_3()
{
    vector<string> words = {"b", "dee", "a", "ee", "c"};
    string s = "cebcecceab";

    cout << boldWords(words, s) << endl;
}

int main()
{
    //test_1();

    //test_2();

    test_3();
    // size_t t = s.find("deal");

    // cout << t << endl;
}