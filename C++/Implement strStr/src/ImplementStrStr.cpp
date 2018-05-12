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
        int index = 0;
        for ( auto it = haystack.begin(); it < haystack.end(); ++it){
        	auto it2 = needle.begin();
        	if (*it == *it2) {
        		auto tempIt = it;
        		while (tempIt < haystack.end() && it2 < needle.end() && *it2 == *tempIt) {
        			++tempIt;
        			++it2;
        		}
        		if(it2==needle.end()) {
        			return index;
        		}
        	}
        	index++;
        }
        return -1;
    }
};

int main() {
	int x = Solution::strStr("Hello","ll");
	cout << x << "\n";
	return 0;
}
