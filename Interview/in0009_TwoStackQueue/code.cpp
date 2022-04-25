#include <bits/stdc++.h>

using namespace std;

class CQueue {
private:
    stack<int> in;
    stack<int> out;
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        in.push(value);
    }
    
    int deleteHead() {
        if(in.empty()) return -1;
        while (!in.empty())
        {
            int temp = in.top();
            out.push(temp);
            in.pop();
        }
        int res = out.top();
        out.pop();

        while (!out.empty())
        {
            int temp = out.top();
            in.push(temp);
            out.pop();
        }
        return res;
        
    }
};