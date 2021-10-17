#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void printMatrix(vector<vector<int> > &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << ',';
        }
        cout << endl;
    }
}

vector<vector<int> > updateMatrix(vector<vector<int> > &mat)
{
    int n = mat.size(), m = mat[0].size();
    vector<vector<int> > res(n, vector<int>(m));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = -1;
        }
    }

    queue<pair<int, int> > q;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                res[i][j] = 0;
                pair<int, int> p(i, j);
                q.push(p);

                while (!q.empty())
                {

                    int x = q.front().first, y = q.front().second;
                    q.pop();

                    for (int i = 0; i < 4; i++)
                    {

                        int mx = x + dx[i];
                        int my = y + dy[i];
                        int dis = res[x][y] + 1;
                        //cout << dis << endl;
                        if (mx >= 0 && mx < n && my >= 0 && my < m)
                        {
                            if (res[mx][my] == -1)
                            {
                                pair<int, int> p(mx, my);
                                q.push(p);

                                res[mx][my] = dis;
                            }
                            else if (res[mx][my] != -1 && res[mx][my] > dis)
                            {
                                pair<int, int> p(mx, my);
                                q.push(p);

                                res[mx][my] = dis;
                            }
                        }
                    }
                }
                printMatrix(res);
                cout << endl;
            }
        }
    }

    return res;
}

int main()
{
    vector<int> a;
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    vector<int> b;
    b.push_back(0);
    b.push_back(1);
    b.push_back(0);
    vector<int> c;
    c.push_back(1);
    c.push_back(1);
    c.push_back(1);

    vector<vector<int> > mat;
    mat.push_back(a);
    mat.push_back(b);
    mat.push_back(c);

    vector<vector<int> > up = updateMatrix(mat);

    printMatrix(up);
}