#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution
{

private:
    vector<vector<int>> relation;

    vector<int> edges;

    bool loop;

public:
    void dfs(int u)
    {
        edges[u] = 1;

        for (int v : relation[u])
        {
            if (edges[v] == 0)
            {
                dfs(v);

                if (loop)
                {
                    return;
                }
            }
            else if (edges[v] == 1)
            {
                loop = true;
                return;
            }
        }

        edges[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        relation.resize(numCourses);

        edges.resize(numCourses);

        for (const auto& info: prerequisites)
        {
            relation[info[1]].push_back(info[0]);
        }

        for (int i = 0; i < numCourses && !loop; i++)
        {
            if (!edges[i])
            {
                dfs(i);
            }
            
        }

        if (loop)
        {
            return false;
        }

        return true;
        
        
    }
};

int main()
{
    vector<vector<int>> relations_1 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    Solution s;
    if(s.canFinish(4, relations_1))
    {
        cout << "Yes you can finish them in order\n";
    } else
    {
        cout << "No, not a good idea. There is a loop\n";
    }
    


    
}