#include <bits/stdc++.h>

using namespace std;

int minArray(vector<int> &numbers)
{
    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i] < numbers[i-1]) return numbers[i];
    }
    return numbers[0];
}