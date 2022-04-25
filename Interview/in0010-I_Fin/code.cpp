#include <bits/stdc++.h>

using namespace std;

int fib(int n)
{
    if (n==0) return 0;
    if (n==1) return 1;
    if (n==2) return 1;
    vector<int> dp(n,0);

    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i < n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];

    }
    return dp[n-1];
}

int main()
{
    cout << fib(3) << fib(4) << endl;
}