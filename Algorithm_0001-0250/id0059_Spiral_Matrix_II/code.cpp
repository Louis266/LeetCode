#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{

    vector<vector<int>> res (n, vector<int>(n, 0));
    int startx = 0;
    int starty = 0;

    int count = 1;// var for iteration
    int offset = 1;
    int loop = n/2;
    int mid = n/2;

    int i,j;

    while (loop --)
    {
        j = starty;
        i = startx;
        for (j = starty; j < starty + n - offset; j++)
        {
            res[startx][j] = count++;
        }

        for (i = startx; i < startx + n - offset; i++)
        {
            res[i][starty] = count++;
        }

        for (; j > starty; j--)
        {
            res[i][j] = count++;
        }
        for (; i > startx; i--)
        {
            res[i][j] = count++;
        }
        
        startx++;
        starty++;
        
        offset+=2;
            
    }
    

    if (n%2 == 1)
    {
        res[mid][mid] = count;
    }
    
    return res;
}