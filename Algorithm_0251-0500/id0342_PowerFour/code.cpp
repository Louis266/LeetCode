#include <iostream>

using namespace std;

bool isPowerOfFour(int n) {

    
    while(n/4 != 0){
        if (n%4 != 0) return false; 
        n = n/4;
    }
    if (n == 1) return true;

    else return false;
}

int main () {
    cout << isPowerOfFour(8) << endl;

    cout << isPowerOfFour(5) << endl;


    cout << isPowerOfFour(1) << endl;
}