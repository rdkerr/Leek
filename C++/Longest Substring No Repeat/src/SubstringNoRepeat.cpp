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
#include <vector>
using namespace std;

//O(n^2) time and O(n) space
int lengthOfLongestSubstring(string s) {
	int n = s.length();
	    if (n == 0) return 0;

	    int *T = new int[n];
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
				if (T[i] > max ) {
					max = T[i];

				}
			}
			else {
				T[i] = min(i-j,T[i-1]+1);

				if (T[i] > max ) {
					max = T[i];

				}
			}
		}
		return max;
}

// O(n) space O(128) space
int lengthOfLongestSubstring2(string s) {
	int T[128] = {0};
	int n = s.length();
	int m = 0;
	for (int j = 0, i = 0 ; j < n; j++) {
		i = max(T[int(s[j])],i);
		m = max(m,j-i+1);
		T[int(s[j])] = j+1;
	}
	return m;
}

        // try to extend the range [i, j]
        //for (int j = 0, i = 0; j < n; j++) {
        //    i = Math.max(index[s.charAt(j)], i);
        //    ans = Math.max(ans, j - i + 1);
        //    index[s.charAt(j)] = j + 1;
        //}


int main() {
	string x = "c";
	int y;
	y = lengthOfLongestSubstring(x);
	cout << y << endl;
	y = lengthOfLongestSubstring2(x);
	cout << y << endl;
	return 0;
}

