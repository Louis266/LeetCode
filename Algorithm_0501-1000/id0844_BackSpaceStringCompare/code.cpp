#include <iostream>
#include <string>
#include <stdlib.h>
#include <stack>

using namespace std;

bool backspaceCompare(string S, string T) {
        return build(S) == build(T);
    }

    string build(string str) {
        string ret;
        for (char ch : str) {
            if (ch != '#') {
                ret.push_back(ch);
            } else if (!ret.empty()) {
                ret.pop_back();
            }
        }
        return ret;
    }


int main()
{
    string s = "cde";
    string t = "cde";

    cout << backspaceCompare(s, t) << endl;
}