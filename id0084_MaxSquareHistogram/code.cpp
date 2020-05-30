#include <vector>
#include <iostream>

using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int max = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int h = heights[i];
        int area = h;
        for (int pre = i - 1; pre >= 0; pre--)
        {
            if (heights[pre] >= h)
            {
                area += h;
            }
            else
            {
                break;
            }
        }
        for (int post = i + 1; post < heights.size(); post++)
        {
            if (heights[post] >= h)
            {
                area += h;
            }
            else
            {
                break;
            }
        }
        if (area > max)
        {
            max = area;
        }
        
    }
    return max;
}

int main()
{
    vector<int> h_1 = {2,1,5,6,2,3};
    // vector<int> h_1 = {2,1,5,6,2,3};
    // vector<int> h_1 = {2,1,5,6,2,3};
    

    cout << largestRectangleArea(h_1) << endl;
}