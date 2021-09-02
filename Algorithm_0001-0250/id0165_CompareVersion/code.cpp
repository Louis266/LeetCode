#include <iostream>
#include <vector>

using namespace std;

int compareVersion(string version1, string version2)
{
    int len_1 = version1.size();
    int len_2 = version2.size();

    int i = 0;
    int j = 0;

    while (i < len_1 || j < len_2)
    {
        int num_1 = 0;
        int num_2 = 0;
        while (i < len_1 && version1[i] != '.')
        {
            num_1 = num_1 * 10 + version1[i++] - '0';
        }

        if (i < len_1 - 1)
            ++i;

        while (j < len_2 && version2[j] != '.')
        {
            num_2 = num_2 * 10 + version2[j++] - '0';
        }
        if (j < len_2 - 1)
            ++j; 

        if (num_1 > num_2)
            return 1;
        else if (num_1 < num_2)
            return -1;
    }

    return 0;
}

int main()
{
    string s1 = "1.2.3";
    string s2 = "1.1.2";

    cout << compareVersion(s1, s2) << endl;
    
}
