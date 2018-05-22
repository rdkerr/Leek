//============================================================================
// Name        : SubstringWithConcatenationOfAllWords.cpp
// Author      : Roger Kerr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;


class Solution {
public:
    static vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int> res;
    	int length = s.length();
    	int wordCount = words.size();
    	int wordLength = words[0].size();
    	if (!length || !wordCount) {
    		return res;
    	}
    	map<string,int> wordMap;
    	for(string word:words) {
    		wordMap[word]++;
    	}
		for(int windowStart=0; windowStart<wordLength; windowStart++){
			unsigned int windowStartTemp = windowStart;
			map<string,int> tempMap;
			int tempCount = 0;
			// Slide the window of wordLength
			for(unsigned int i=windowStart; i<s.size(); i+=wordLength){
				string str = s.substr(i, wordLength);
				tempMap[str]++;
				tempCount++;
				// Remove words added to temp map, concatenated words not found
				while(tempMap[str]>wordMap[str] && windowStartTemp<=i){
					string lstr = s.substr(windowStartTemp,wordLength);
					tempMap[lstr]--;
					tempCount--;
					windowStartTemp+=wordLength;
				}
				// Add starting index if all words found
				if(tempCount==wordCount){
					res.push_back(windowStartTemp);
					string lstr = s.substr(windowStartTemp,wordLength);
					tempMap[lstr]--;
					tempCount--;
					windowStartTemp+=wordLength;
				}
			}
		}
        return res;
    }
};


int main() {
	vector<string> words;
	words.push_back("foo");
	words.push_back("bar");
	string s = "foobarthebarfoofooobar";
	vector<int> ans = Solution::findSubstring(s,words);
	for (auto a : ans) {
		cout << a << "\n";
	}
	cout << "FINISHED\n";
	return 0;
}
