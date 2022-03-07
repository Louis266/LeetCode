#include <string>
#include <iostream>
#include <stack>

using namespace std;

string convertToBase7(int num)
{
    int flag = 0;
    stack<int> s;
    if (num == 0)
    {
        return "0";
    }

    if (num < 0)
    {
        num = 0 - num;
        flag = 1;
    }
    
    while (num/7 != 0)
    {
        s.push(num%7);
        num = num/7;
    }
    
    s.push(num);

    string res = "";

    if (flag == 1)
    {
        res.push_back('-');
    }
    
    while (!s.empty())
    {
        int i = s.top();
        char c = i + '0';
        res.push_back(c);
        s.pop();
    }
    
    
    return res;
}

int main()
{
    int num = 100;

    cout << convertToBase7(num) << endl;

    cout << convertToBase7(-7) << endl;

    cout << -7%2 << endl;
}