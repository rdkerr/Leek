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
    	stack<int> ms;
		ms.push(-1);
		int length = s.size();
		for(int i = 0; i < length ; i++) {
			char ch = s[i];
			if(ch == ')' && ms.top() >= 0 && s[ms.top()] == '(') {
			ms.pop();
			} else{
				ms.push(i);
			}
		}
		ms.push(s.size());
		int maxLen = 0;
		while(ms.size() > 1) {
			int top = ms.top();
			ms.pop();
			int curLen = top - ms.top() - 1;
			if (curLen > maxLen) {
				maxLen = curLen;
			}
		}
		return maxLen;
    }
};

int main() {
	int ans = Solution::longestValidParentheses(")(()()()())))())");
	cout << ans << endl;
	return 0;
}
