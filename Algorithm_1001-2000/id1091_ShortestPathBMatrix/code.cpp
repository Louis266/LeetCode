#include <vector>
#include <queue>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    int ans = 1;
    //因为起始位置算一块方块，所以初始值为一
    if (grid[n - 1][n - 1] == 1 || grid[0][0] == 1)
        return -1;
    //首先排除起点和终点到不了的情况
    if (n == 0)
        return -1;
    //再排除空数组的情况
    queue<pair<int, int>> que;
    pair<int, int> p(n - 1, n - 1);
    grid[n - 1][n - 1] = 1;
    //将走过的方块设置为一，避免重复
    que.push(p);
    //让终点入队 反向查找
    while (!que.empty())
    { //队列为空时结束循环
        int l = que.size();
        //每一步分支的数量，走完这一步的分支之后才能让方块数加一
        for (int i = 0; i < l; i++)
        {
            int x1 = que.front().first;
            int x2 = que.front().second;
            que.pop();
            //记得头元素出队
            if (x1 == 0 && x2 == 0)
            {
                return ans; //当走到起点时，便可返回所经过的方块数
            }
            //接下来是向八个方向方块判断是否可以入队，入队后需要将入队的方块值设置为一，避免重复入队
            if (x1 > 0 && grid[x1 - 1][x2] == 0)
            {
                pair<int, int> temp(x1 - 1, x2);
                grid[x1 - 1][x2] = 1;
                que.push(temp);
            }
            if (x2 > 0 && grid[x1][x2 - 1] == 0)
            {
                pair<int, int> temp(x1, x2 - 1);
                grid[x1][x2 - 1] = 1;
                que.push(temp);
            }
            if (x1 > 0 && x2 > 0 && grid[x1 - 1][x2 - 1] == 0)
            {
                pair<int, int> temp(x1 - 1, x2 - 1);
                grid[x1 - 1][x2 - 1] = 1;
                que.push(temp);
            }
            if (x1 < n - 1 && grid[x1 + 1][x2] == 0)
            {
                pair<int, int> temp(x1 + 1, x2);
                grid[x1 + 1][x2] = 1;
                que.push(temp);
            }
            if (x2 < n - 1 && grid[x1][x2 + 1] == 0)
            {
                pair<int, int> temp(x1, x2 + 1);
                grid[x1][x2 + 1] = 1;
                que.push(temp);
            }
            if (x1 < n - 1 && x2 < n - 1 && grid[x1 + 1][x2 + 1] == 0)
            {
                pair<int, int> temp(x1 + 1, x2 + 1);
                grid[x1 + 1][x2 + 1] = 1;
                que.push(temp);
            }
            if (x1 < n - 1 && x2 > 0 && grid[x1 + 1][x2 - 1] == 0)
            {
                pair<int, int> temp(x1 + 1, x2 - 1);
                grid[x1 + 1][x2 - 1] = 1;
                que.push(temp);
            }
            if (x1 > 0 && x2 < n - 1 && grid[x1 - 1][x2 + 1] == 0)
            {
                pair<int, int> temp(x1 - 1, x2 + 1);
                grid[x1 - 1][x2 + 1] = 1;
                que.push(temp);
            }
        }
        ans++;
        //每走完一层方块，走过的方块数便加一
    }
    return -1;
}