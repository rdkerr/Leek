//============================================================================
// Name        : ImplementStrStr.cpp
// Author      : Roger Kerr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    static int strStr(string haystack, string needle) {
        if(needle == "") {
        	return 0;
        }
        if (haystack.size() < needle.size()) {
        	return -1;
        }
        for (int i = 0 ; i <= haystack.size() - needle.size() ; i ++) {
        	if(haystack[i]==needle[0]) {
        		int j = 1;
        		while (j < needle.size() && haystack[i+j] == needle[j]) {
        			j++;
        		}
        		if (j== needle.size()) {
        			return i;
        		}
        	}
        }
        return -1;
    }
};

int main() {
	int x = Solution::strStr("mississippi","mississippi");
	cout << x << "\n";
	return 0;
}
