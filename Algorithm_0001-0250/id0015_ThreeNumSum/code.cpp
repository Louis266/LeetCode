#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int flag = 0;

bool is_element_in_vector(vector<int> v,int element){
    vector<int>::iterator it;
    it=find(v.begin(),v.end(),element);
    if (it!=v.end()){
        return true;
    }
    else{
        return false;
    }
}


void backTrack(int i, int cs, int count, vector<int> nums, vector<int> &trace, vector<vector<int> > &res)
{
    if (count == 3 || i == nums.size())
    {
        
        if (cs == 0 && !trace.empty() && count == 3)
        {
            for (int i = 0; i < res.size(); i++)
            {
                if (is_element_in_vector(res[i], trace[0])&&is_element_in_vector(res[i], trace[1])&&is_element_in_vector(res[i], trace[2])){
                    if (res[i][0] == 0 && res[i][1] == 0 &&res[i][2] == 0 )
                        flag = 1;
                    if (trace[0] == 0 && trace[1] == 0 && trace[2] == 0 && flag == 0)
                        flag = 1;
                    else
                        return;
                }
            }
            
            res.push_back(trace);
        }
        return;
    }

    backTrack(i + 1, cs, count, nums, trace, res);

    if (count + 1 <= 3)
    {
        //cs += nums[i];
        trace.push_back(nums[i]);
        
        backTrack(i + 1, cs+nums[i], count + 1, nums, trace, res);
        
        trace.pop_back();
    }
}

vector<vector<int> > threeSum(vector<int> nums)
{
    vector<vector<int> > res;

    int i = 0;
    int cs = 0;
    int count = 0;
    vector<int> trace;

    backTrack(i, cs, count, nums, trace, res);
    
    return res;
}

/*
int main(){
    vector<int> nums = {0,3,0,1,1,-1,-5,-5,3,-3,-3,0};
    vector<int> nums_0 = {-1,0,1,2,-1,-4};


    vector<vector<int>> res = threeSum(nums);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " -> ";
        }
        cout << endl;
    }
    
}*/