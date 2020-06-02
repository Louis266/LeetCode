#include <limits.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
        minimal.push(INT_MAX);
    }

    void push(int x)
    {
        data.push(x);
        minimal.push(min(minimal.top(), x));
    }

    void pop()
    {

        data.pop();
        minimal.pop();
    }

    int top()
    {
        return data.top();
    }

    int getMin()
    {
        return minimal.top();
    }

private:
stack<int>data;
stack<int> minimal;
};

int main()
{

    MinStack s;

    s.push(8);
    s.push(9);
    s.push(10);

    cout << s.getMin() << endl;

    s.pop();

    cout << s.getMin() << endl;
}