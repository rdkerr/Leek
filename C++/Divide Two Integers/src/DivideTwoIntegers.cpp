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
    	if(divisor == 0 ||(dividend == INT_MIN && divisor == -1)) {
			return INT_MAX;
		}
		else if(divisor == 1){
			return dividend;
		}
		else if(divisor == dividend) {
			return 1;
		}
    	int sign = (dividend > 0) ^ (divisor > 0);
    	unsigned int top, bot;
    	int result = 0;
    	if (dividend < 0) {
    		top = 0 - dividend;
    	}
    	else {
    		top = dividend;
    	}
    	if (divisor < 0) {
			bot = 0 - divisor;
			}
		else {
			bot = divisor;
		}
    	for (int i = 31; i >= 0 ; i--) {
    		if((top>>i) >= bot) {
    			result = (result<<1) | 1;
    			top -= bot << i;
    		}
    		else {
    			result <<= 1;
    		}
    	}
    	if(sign) {
    		return 0 - result;
    	}
    	return result;
    }
};

int main() {
	int res = Solution::divide(2147483647,-2);
	cout << res << endl;
	return 0;
}
