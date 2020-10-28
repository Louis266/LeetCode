#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{

    unordered_map<int, int> occur;
    for (const auto &x : arr)
    {
        occur[x]++;
    }
    unordered_set<int> times;
    for (const auto &x : occur)
    {
        times.insert(x.second);
    }
    return times.size() == occur.size();
}

int main()
{
    vector<int> arr;
    // arr.push_back(3);
    // arr.push_back(5);
    // arr.push_back(-2);
    // arr.push_back(-3);
    // arr.push_back(-6);
    // arr.push_back(-6);

    //[5,-2,-2,1,5,-2]

    arr.push_back(5);
    arr.push_back(-2);
    arr.push_back(-2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(-2);
    // arr.push_back(1);
    // arr.push_back(2);

    if (uniqueOccurrences(arr))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}