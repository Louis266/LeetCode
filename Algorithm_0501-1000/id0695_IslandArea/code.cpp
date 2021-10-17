#include <vector>

using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

void dfs(vector<vector<int> > &grid, int x, int y, vector<vector<int> > &visited, int &area)
{
    visited[x][y] = 1;
    if (grid[x][y] == 1)
    {
        area += 1;
        for (int i = 0; i < 4; i++)
        {
            int mx = x + dx[i], my = y + dy[i];
            if (mx >= 0 && mx < grid.size() && my >= 0 && my < grid[0].size())
            {
                dfs(grid, mx, my, visited, area);
            }
        }
    }
}

int maxAreaOfIsland(vector<vector<int> > &grid)
{
    int n = grid.size(), m = grid[0].size();
    int res = 0;

    vector<vector<int> > visited(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int area = 0;
            if (visited[i][j] != 1)
            {
                dfs(grid, i, j, visited, area);
                if (area >= res)
                    res = area;
            }
        }
    }

    return res;
}

