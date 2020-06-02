#include <queue>
#include <iostream>

using namespace std;

class MyStack
{
private:
    queue<int> q1;
    queue<int> q2;
    int size;

public:
    /** Initialize your data structure here. */
    MyStack()
    {
        size = 0;
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q1.push(x);
        size++;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        for (int i = 0; i < size - 1; i++)
        {
            int temp = q1.front();
            q2.push(temp);
            q1.pop();
        }
        int d = q1.front();
        q1.pop();
        size--;
        for (int i = 0; i < size; i++)
        {
            int temp = q2.front();
            q1.push(temp);
            q2.pop();
        }
        return d;
    }

    /** Get the top element. */
    int top()
    {
        for (int i = 0; i < size - 1; i++)
        {
            int temp = q1.front();
            q2.push(temp);
            q1.pop();
        }
        int d = q1.front();
        q1.pop();
        q2.push(d);
        for (int i = 0; i < size; i++)
        {
            int temp = q2.front();
            q1.push(temp);
            q2.pop();
        }
        return d;   
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.size()==0? true:false;
    }
};

int main()
{
    MyStack s;

    s.push(1);
    s.push(2);
    cout << s.pop() <<endl;

    if (s.empty())
    {
        cout << "empty" << endl;
    }
    
}