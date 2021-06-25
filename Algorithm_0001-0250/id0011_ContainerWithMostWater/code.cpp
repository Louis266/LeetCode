#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height){
    int l = 0, r = height.size() - 1;

    int ans = 0;

    while (l < r)
    {
        int area = min(height[r],height[l]) * (l-r);

        ans = max(ans,area);

        if(height[l] <= height[r]) {
            ++l;
        } else {
            --r;
        }
        //if(height[l] > height[r]) r--;
    }
    
    return ans;

}

int main(){


}