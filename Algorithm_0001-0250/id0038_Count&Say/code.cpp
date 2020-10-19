#include <string>
#include <iostream>

using namespace std;

string countAndSay(int n)
{
    if(n==1) return "1";
        string pre=countAndSay(n-1),ans;
        int len=pre.size();
        int i=0;
        for(int j=0;j<=len;j++)
        {
            if(pre[i]==pre[j])
            {
                 continue;
            }
            else
            {
                ans+=to_string(j-i)+pre[i];   
                i=j;
                j--;
            }
        }
        return ans;   

}

int main()
{

}