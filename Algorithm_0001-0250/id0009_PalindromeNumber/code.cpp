#include <iostream>

using namespace std;

bool isPalindrome(int x)
{
    if (x<0) {
        return false;
    }
    int top = -1;
    char num[10];
    while (x != 0) {
        num[++top] = x % 10;
        x = x / 10;
    }
    int i = 0;
    while (i < top)
    {
        if (num[i] != num[top])
        {
            return false;
        }

        i++;
        top--; 
    }
    return true;
}

int main()
{
    cout << isPalindrome(1212) << endl;
}
