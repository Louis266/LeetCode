#include <vector>
#include <iostream>
using namespace std;

vector<int> father(26);

int _find(int i)
{
    while (i != father[i])
    {
        father[i] = father[father[i]]; 
        i = father[i];
    }
    return i;
}

bool equationsPossible(vector<string> &equations)
{
    if (equations.empty())
        return true;

    for (int i = 0; i < 26; i++)
    {
        father[i] = i;
    }
    for (int i = 0; i < equations.size(); i++)
    {
        if (equations[i][1] == '=')
        { 
            int fa1 = _find(equations[i][0] - 'a');
            int fa2 = _find(equations[i][3] - 'a');
            if (fa1 != fa2)
                father[fa1] = fa2;
        }
    }
    for (int i = 0; i < equations.size(); i++)
    {
        if (equations[i][1] == '!')
        {
            int fa1 = _find(equations[i][0] - 'a');
            int fa2 = _find(equations[i][3] - 'a');
            if (fa1 == fa2)
                return false;
        }
    }
    return true;
}

int main()
{
    vector<string> vec = {"a==b","b==c","a==c"};

    cout << equationsPossible(vec) << endl;
}