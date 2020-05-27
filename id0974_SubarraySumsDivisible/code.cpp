#include <vector>
#include <iostream>
#include <map>

using namespace std;

//通常，涉及连续子数组问题的时候，我们使用前缀和来解决。
int subarraysDivByK(vector<int> &A, int K)
{
    // int count = 0;

    // for (int i = 0; i < A.size(); i++)
    // {
    //     int sum = 0;
    //     for (int j = i; j < A.size(); j++)
    //     {
    //         sum += A[j];
    //         if (sum % K == 0)
    //         {
    //             count++;
    //         }
    //     }
    // }

    // return count;
    map<int, int> record = {{0, 1}};
        int sum = 0, ans = 0;
        for (int elem: A) {
            sum += elem;
            // 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
            int modulus = (sum % K + K) % K;
            if (record.count(modulus)) {
                ans += record[modulus];
            }
            ++record[modulus];
        }
        return ans;
}

int main()
{
    vector<int> vec = {4,5,0,-2,-3,1};
    int k = 5;

    cout << subarraysDivByK(vec, k) << endl;
}