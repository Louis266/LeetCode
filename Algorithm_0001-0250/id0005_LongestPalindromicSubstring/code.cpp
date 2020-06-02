#include <vector>
#include <string>
#include <iostream>

using namespace std;

string longestPalindrome(string s)
{
    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n));
    string res;

    for (int l = 0; l < n; l++)
    {
        for (int i = 0; i + l < n; i++)
        {
            int j = i + l;

            if (l == 0)
            {
                dp[i][j] = 1;
            }
            else if (l == 1)
            {
                dp[i][j] = (s[i] == s[j]);
            }
            else
            {
                dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
            }
            if (dp[i][j] && l + 1 > res.size())
            {
                res = s.substr(i, l+1);
            }
        }
    }
    return res;
}

int main()
{
    string s1 = "abba";

    string s2 = "abbadkdonmgohhha";

    string s3 = "asdfghjklkjhgfdsa";

    cout << longestPalindrome(s1) << endl;
    cout << longestPalindrome(s2) << endl;
    cout << longestPalindrome(s3) << endl;
    
}