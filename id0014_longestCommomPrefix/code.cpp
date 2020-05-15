#include <vector>
#include <iostream>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string s ="";
    int minLen = 0;
    for (int i = 0; i < strs.size(); i++)
    {
        if (strs[i].size() > minLen)
        {
            minLen = strs[i].size();
        }
    }
    
    for (int i = 0; i < minLen; i++)
    {
        char c = strs[0][i];
        int flag = 1;
        for (int j = 0; j < strs.size(); j++)
        {
            if (c != strs[j][i] )
            {
                flag = 0;
                break;
            }
            
        }
        if (flag == 0)
        {
            return s;
        }else
        {
            s+=c;
        }
        
        
    }
    
    return s;
   
}
