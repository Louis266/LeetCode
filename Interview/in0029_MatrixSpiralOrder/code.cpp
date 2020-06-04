#include <vector>
#include <iostream>

using namespace std;

const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    if (matrix.size() == 0 || matrix[0].size() == 0)
    {
        return {};
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols));

    int total = rows * cols;
    vector<int> res(total);

    int r = 0;
    int c = 0;

    int dir = 0 ;

    for (int i = 0; i < total; i++)
    {
        res[i] = matrix[r][c];

        visited[r][c] = true;

        int nextR = r + directions[dir][0];
        int nextC = c + directions[dir][1];
        if (nextR < 0 || nextR >= rows || nextC >= cols || nextC < 0 || visited[nextR][nextC])
        {
            dir = (dir + 1) % 4;
        }
        
        r += directions[dir][0];
        c += directions[dir][1];
    }

    return res;
    

}

int main()
{
    vector<vector<int>> vec = {{1,2,3},{4,5,6},{7,8,9}};

    vector<int> res = spiralOrder(vec);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    
}
