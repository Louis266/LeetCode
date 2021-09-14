#include <stack>
#include <string>
#include <iostream>

using namespace std;

int balancedStringSplit(string s)
{
    stack<char> save;
    int res = 0;
    for (string::iterator i = s.begin(); i != s.end(); i++)
    {
        if (save.empty())
        {
            save.push(*i);
        }
        else if (save.top() == *i)
        {
            save.push(*i);
        }
        else if (save.top() != *i)
        {
            save.pop();

            if (save.empty())
            {
                res++;
            }
            
        }

        
    }
    return res;
}

int main(){
    string s1 = "RLLLLRRRLR";

    cout << balancedStringSplit(s1) << endl;
}