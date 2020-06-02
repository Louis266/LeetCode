#include <vector>
#include <iostream>

using namespace std;

int surfaceArea(vector<vector<int>> &grid)
{
    int area_size = grid.size();//edge length of the area
    int surface = 0;//area surface
    for (int i = 0; i < area_size; i++)
    {
        for (int j = 0; j < area_size; j++)
        {
            if (grid[i][j] == 0)//if the unit height is 0
            {
                surface += 0;//add 0
            }
            else
            {
                surface += 2; // add the surface area of the bottom and top
                if (i == 0)   // first column
                {
                    if (j == 0) //(0,0)
                    {
                        surface += 4 * grid[0][0];
                    }
                    else // rest of the column
                    {
                        int diff = grid[i][j] - grid[i][j - 1]; //height difference with the formor unit
                        if (diff < 0)                           //if lower
                        {
                            surface += 2 * grid[i][j];
                        }
                        else //if higher
                        {
                            surface += 2 * grid[i][j - 1] + 4 * diff;
                        }
                    }
                }
                else //rest of the columns
                {
                    if (j == 0) //first row
                    {
                        int diff_i = grid[i][j] - grid[i - 1][j];
                        if (diff_i < 0)//no taller
                        {
                            surface += 2 * grid[i][j];
                        }
                        else
                        {
                            surface += 2 * grid[i - 1][j] + 4 * diff_i;
                        }
                    }
                    else
                    {
                        int diff_i = grid[i][j] - grid[i - 1][j];
                        int diff_j = grid[i][j] - grid[i][j - 1];

                        if (diff_i < 0)
                        {
                            surface += 0;
                        }
                        else
                        {
                            surface += 2 * diff_i;
                        }
                        if (diff_j < 0)
                        {
                            surface += 0;
                        }
                        else
                        {
                            surface += 2 * diff_j;
                        }
                    }
                }
            }
        }
    }

    return surface;
}

int main()
{
    vector<vector<int>> v1 = {{2}};

    vector<vector<int>> v2 = {{1, 2}, {3, 4}};

    vector<vector<int>> v3 = {{1, 0}, {0, 2}};

    vector<vector<int>> v4 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    vector<vector<int>> v5 = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
    // cout << v1.size() << endl;
    // cout << v1[1].size();

    cout << "v1's surface: " << surfaceArea(v1) << endl;
    cout << "v2's surface: " << surfaceArea(v2) << endl;
    cout << "v3's surface: " << surfaceArea(v3) << endl;
    cout << "v4's surface: " << surfaceArea(v4) << endl;
    cout << "v5's surface: " << surfaceArea(v5) << endl;

    // vector<vector<int>> v_t = {{2, 2}, {2, 2}};

    // cout << surfaceArea(v_t) << endl;
}