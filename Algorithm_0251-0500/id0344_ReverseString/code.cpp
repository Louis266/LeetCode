#include <vector>

using namespace std;

void reverseEtring (vector<char>& s)
{
    /*
    int i = 0;
    int j = s.size() - 1;

    while (i < j )
    {
        char temp = s[i];

        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;
    }
    */

   for (int i = 0, int j = s.size() - 1; i < s.size()/2; i++, j--)
   {
       swap(s[i], s[j]);
   }
   
}