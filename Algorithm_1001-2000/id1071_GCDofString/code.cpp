#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string gcdOfStrings(string str1, string str2)
{
    if (str1 + str2 != str2 + str1) return "";
    //return str1.substr(0, __gcd((int)str1.length(), (int)str2.length())); 
}

int main()
{
    string str1 = "ABCABC";
    string str2 = "ABCABCABC";

    cout << gcdOfStrings(str1, str2);
}