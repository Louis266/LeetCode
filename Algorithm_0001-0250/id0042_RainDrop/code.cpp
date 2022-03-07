#include <vector>
#include <iostream>
#include <stack>

using namespace std;

/*
 *未考虑左柱子高度高于右侧
int trap(vector<int> &height)
{
    int a = 0;
    int b = a + 1;

    int res = 0;
    while (a != height.size()-1)
    {
        int h = height[a];
        int temp = 0;
        while (height[b] < h && b != height.size() - 1)
        {
            temp += h - height[b];
            b++;
        }

        if (b == height.size() - 1 && height[b] < h)
        {
            a++;
            b = a + 1;
        } else
        {
            res += temp;
            a = b;
            b = a + 1;
        }

    }

    return res;

}

*/

/*
 * 超时
int trap(vector<int> height)
{
    int sum = 0;

    for (int i = 0; i < height.size(); i++)
    {
        if (i == 0 || i == height.size() - 1)
        {
            continue;
        }

        int rHeight = height[i];
        int lHeight = height[i];

        for (int r = i + 1; r < height.size(); r++)
        {
            if (height[r] > rHeight)
            {
                rHeight = height[r];
            }
        }

        for (int l = i- 1; l >= 0; l--)
        {
            if (height[l] > lHeight)
            {
                lHeight = height[l];
            }
            
        }
        
        int h = min (lHeight, rHeight) - height[i];
        if (h > 0)
        {
            sum += h;
        }
        
    }
    return sum;
}
*/

int trap_1(vector<int>& height)
{
    if (height.size() <= 2) return 0;

    vector<int> maxLeft (height.size(), 0);
    vector<int> maxRight (height.size(), 0);

    int size = maxRight.size();

    maxLeft[0] = height[0];

    for (int i = 1; i < size; i++)
    {
        maxLeft[i] = max(height[i], maxLeft[i-1]);
    }

    maxRight[size - 1] = height[size - 1];

    for (int i = size - 2; i >= 0; i--)
    {
        maxRight[i] = max(height[i], maxRight[i+1]);
    }
    
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        int count = min(maxLeft[i], maxRight[i]) - height[i];
        if (count > 0)
        {
            sum += count;
        }
        
    }
    return sum;
    
    
}

int trap(vector<int>& height)
{
    stack<int> st;
    st.push(0);
    int sum = 0;

    for (int i = 1; i < height.size(); i++)
    {
        while (!st.empty() && height[i] > height[st.top()])
        {
            int mid = st.top();
            st.pop();
            if (!st.empty())
            {
                int h = min(height[st.top()], height[i]) - height[mid];
                int w = i - st.top() - 1;
                sum += h * w;
            }
            
        }

        st.push(i);
        
    }
    return sum;
}


int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    vector<int> height_1 = {4, 2, 0, 3, 2, 5};

    vector<int> height_2 = {4, 2, 3};
    cout << trap(height_2) << endl;
}