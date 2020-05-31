#include <vector>
#include <iostream>

using namespace std;

vector<int> distributeCandies(int candies, int num_people)
{
    vector<int> res;
    for (int i = 0; i < num_people; i++)
    {
        res.push_back(0);
    }

    int i = 0;
    while (candies != 0)
    {
        int remain = candies;
        if ((candies -= (i + 1)) >= 0)
        {
            res[i % num_people] += i + 1;

            cout << i % num_people << " plus " << i + 1 << " with " << candies << " left " << endl;
            cout << i << endl;
        }
        else
        {
            res[i % num_people] += remain;
            cout << i % num_people << " plus " << remain << " with " << candies << " left " << endl;
            cout << i << endl;
            break;
        }

        i++;
    }

    return res;
}

int main()
{
    int can = 10;
    int n_p = 3;

    vector<int> vec = distributeCandies(can, n_p);

    for (int i : vec)
    {
        cout << i << "->";
    }
    cout << endl;
}