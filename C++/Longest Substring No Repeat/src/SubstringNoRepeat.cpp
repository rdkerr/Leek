//============================================================================
// Name        : SubstringNoRepeat.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// T(i) = 0
// T(i) = longest substring between s1 and si without repeating a character ending at si
// T(i) = T(i-1) + 1 : if si not found before
// T(i) = i - k for some sk = si
#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
	int n = s.length();
	       if (n == 0) return 0;
	        int T[n];
	    if (n > 0){
		T[0] = 1;
	    }
		int max = 1;
		for (int i = 1 ; i < n ; i ++) {
			int j = i - 1;
			while (j > -1 && s[j] != s[i] ) {
				j--;
			}
			if (j < 0) {
				T[i] = T[i-1]+1;
				cout << "IF:" << s[i];
				if (T[i] > max ) {
					max = T[i];

				}
			}
			else {
				T[i] = i-(j+1);
				cout << "FF:" << s[i];
				if (T[i] > max ) {
					max = T[i];

				}
			}
		}
		return max;
}

int main() {
	string x = "pwwkew";
	int y;
	y = lengthOfLongestSubstring(x);
	cout << y << endl;
	return 0;
}

