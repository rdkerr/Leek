//============================================================================
// Name        : SearchForARange.cpp
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
    static vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> res;
    	return res;
    }
};

int main() {
	vector<int> nums;
	nums.push_back(1);
	int target = 1;
	vector<int> res = Solution::searchRange(nums,target);

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
