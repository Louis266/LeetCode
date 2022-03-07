#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> s;

    int a;
    int b;
    for (vector<string>::iterator i = tokens.begin(); i != tokens.end(); i++)
    {
        if (*i != "+" && *i != "-" && *i != "*" && *i != "/")
        {
            int temp = stoi(*i);
            s.push(temp);
        }
        if (*i == "+" || *i == "-" || *i == "*" || *i == "/")
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            if (*i == "+")
            {
                s.push(a + b);
            }
            if (*i == "-")
            {
                s.push(a - b);
            }
            if (*i == "*")
            {
                s.push(a * b);
            }
            if (*i == "/")
            {
                s.push(a / b);
            }
        }
    }
    return s.top();
}

int main()
{
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    cout << evalRPN(tokens) << endl;
}