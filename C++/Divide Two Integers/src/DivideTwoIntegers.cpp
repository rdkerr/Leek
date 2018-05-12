//============================================================================
// Name        : DivideTwoIntegers.cpp
// Author      : Roger Kerr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    static int divide(int dividend, int divisor) {
        return 1;
    }
};

int main() {
	int res = Solution::divide(7,3);
	cout << res << endl; // prints !!!Hello World!!!
	return 0;
}
