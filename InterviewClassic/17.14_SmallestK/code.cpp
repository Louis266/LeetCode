#include <vector>
#include <iostream>

using namespace std;

vector<int> smallestK(vector<int> &arr, int k)
{
    vector<int> res(arr.begin(), arr.begin() + k);

    for (int i = k; i < arr.size(); i++)
    {
        int max = res[0];
        int n = 0;
        for (int i = 0; i < k; i++)
        {
            if (res[i] > max)
            {
                max = res[i];
                n = i;
            }
        }
        if (arr[i] < max)
        {
            res[n] = arr[i];
        }
        
    }

    return res;
}

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(9);

    vector<int> res = smallestK(vec, 4);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << "->" ;
    }
    cout << endl;





}