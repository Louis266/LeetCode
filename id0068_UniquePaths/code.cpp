#include <vector>
#include <iostream>

using namespace std;

int uniquePaths(int m, int n)
{
    //vector<vector<int>> vec;

    // vec.resize(m);

    // for (vector<int> i : vec)
    // {
    //     i.resize(n);
    // }

    int **vec = new int*[m];

    for (int i = 0; i < m; i++)
    {
        vec[i] = new int[n];
    }
    

    for (int i = 0; i < m; i++)
    {
        vec[i][0] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        vec[0][i] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
        }
    }

    return vec[m-1][n-1];
}

int main()
{
    int m = 2;
    int n = 2;

    cout << uniquePaths(m,n) << endl;
}