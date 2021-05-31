#include <vector>
#include <iostream>

using namespace std;

int totalHammingDistance_original(vector<int>& nums) {
    int x = 0;
    for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
    {
        x = x ^ *i;
    }
    int sum = 0;

    while (x!=0)
    {
        sum+= x%2;
        x = x/2;
    }
    
    

    return sum;
}

int totalHammingDistance(vector<int>& nums) {
    int ans = 0, n = nums.size();
        for (int i = 0; i < 30; ++i) {
            int c = 0;
            for (int val : nums) {
                c += (val >> i) & 1;
            }
            ans += c * (n - c);
        }
        return ans;
}

int main(){
    //int x = 6^8;
    //cout << x << endl;

    vector<int> n;
    n.push_back(4);
    n.push_back(14);

    n.push_back(2);
    
    cout << totalHammingDistance(n) << endl;
}