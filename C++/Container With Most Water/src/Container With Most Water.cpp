//============================================================================
// Name        : Container.cpp
// Author      : Roger Kerr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

// O(n)
int maxArea(vector<int>& height) {
	int begin = 0;
	int end = height.size() - 1;
	int area = 0;
	while (begin < end) {
		int length = min(height[begin], height[end]);
		int width = end - begin;
		area = max(area, length*width);
		while (height[begin] <= length && begin < end) {
			begin++;
		}
		while (height[end] <= length && begin < end) {
			end--;
		}

	}
    return area;
}

int main() {
	vector<int> vec (2,1);
	int x = maxArea(vec);
	cout << x << endl; // prints !!!Hello World!!!

	return 0;
}

