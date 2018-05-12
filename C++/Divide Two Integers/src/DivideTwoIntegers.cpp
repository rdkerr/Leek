//============================================================================
// Name        : DivideTwoIntegers.cpp
// Author      : Roger Kerr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    static int divide(int dividend, int divisor) {
    	int result = 0;
    	int sign = 0;
    	if (dividend < 0) {
    		sign++;
    		dividend = 0 - dividend;
    		if (dividend < 0) {
    			return INT_MAX - 1;
    		}
    	}
    	if (divisor < 0) {
    		sign++;
    		divisor = 0 - divisor;
    	}
    	int total = divisor;
    	cout << (divisor << 1);
    	while (total <= dividend) {
    		total += divisor;
    		result++;
    		if (total < divisor) {
    			return INT_MAX -1;
    		}
    	}
    	if (sign != 1) {
    		return result;
    	}
    	else {
    		return 0 - result;
    	}
    }
};

int main() {
	int res = Solution::divide(-112,-12);
	//cout << res << endl;
	return 0;
}
