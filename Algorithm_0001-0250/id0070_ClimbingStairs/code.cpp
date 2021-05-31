#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int climbStairs(int n) {
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    
    
    return climbStairs(n-1)+climbStairs(n-2);
}

int climbStairs_2(int n) {
    int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q; 
            q = r; 
            r = p + q;
        }
        return r;
}

int climbStairs_3(int n) {
    double sqrt5 = sqrt(5);
    double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
    return (int)round(fibn / sqrt5);

}

int main(){
    cout<< climbStairs(3) << endl;
}