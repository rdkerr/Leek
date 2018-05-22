//============================================================================
// Name        : SubstringWithConcatenationOfAllWords.cpp
// Author      : Roger Kerr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    static vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int> res;
        return res;
    }
};


int main() {
	vector<string> words;
	words.push_back("foo");
	words.push_back("bar");
	string s = "foobartheboofar";
	vector<int> ans = Solution::findSubstring(s,words);
	for (auto a : ans) {
		cout << a << "\n";
	}
	cout << "FINISHED\n";
	return 0;
}
