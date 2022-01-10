#include <vector>

using namespace std;

void dfs(vector<vector<char>> &grid, int x, int c)
{
    int nx = grid.size();
    int ny = grid[0].size();

    grid[x][c] = '0';
    if (x - 1 >= 0 && grid[x - 1][c] == '1')
        dfs(grid, x - 1, c);
    if (x + 1 < nx && grid[x + 1][c] == '1')
        dfs(grid, x + 1, c);
    if (c - 1 >= 0 && grid[x][c - 1] == '1')
        dfs(grid, x, c - 1);
    if (c + 1 < nx && grid[x][c + 1] == '1')
        dfs(grid, x, c + 1);
}

int numIslands(vector<vector<char>> &grid)
{
    int nx = grid.size();
    if (!nx)
        return 0;
    int nc = grid[0].size();

    int num_islands = 0;

    for (int x = 0; x < nx; ++x)
    {
        for (int c = 0; c < nc; ++c)
        {
            if (grid[x][c] == '1')
            {
                ++num_islands;
                dfs(grid, x, c);
            }
        }
    }

    return num_islands;
}