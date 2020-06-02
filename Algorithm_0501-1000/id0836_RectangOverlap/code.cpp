#include <vector>
#include <iostream>

using namespace std;

bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
{
    return !(rec1[2] <= rec2[0] || // left
             rec1[3] <= rec2[1] || // bottom
             rec1[0] >= rec2[2] || // right
             rec1[1] >= rec2[3]);
}

int main()
{
    int r1[4] = {0,0,2,2};
    int r2[4] = {1,1,3,3};
    vector<int> rec1(r1, r1+4);
    vector<int> rec2(r2, r2+4);

    cout << isRectangleOverlap(rec1, rec2);
}