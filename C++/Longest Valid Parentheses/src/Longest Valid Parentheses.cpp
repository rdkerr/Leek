//============================================================================
// Name        : Longest.cpp
// Author      : Roger Kerr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    static int longestValidParentheses(string s) {
    	if(s.length() < 2) {
    		return 0;
    	}
    	int ret = 0;
    	int length = s.length();
    	stack<char> stck;
    	for (int i = 0 ; i < length ; i ++) {
    		if(s[i]==')') {
    			if(!stck.empty()) {
    				stck.pop();
    				ret +=2;
    			}
    		}
    		else {
    			stck.push(')');
    		}
    	}
        return ret;
    }
};

int main() {
	int ans = Solution::longestValidParentheses("(()");
	cout << ans << endl; // prints !!!Hello World!!!
	return 0;
}
