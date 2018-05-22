//============================================================================
// Name        : NextPermutation.cpp
// Author      : Roger Kerr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static void nextPermutation(vector<int>& nums) {
    	bool found = false;
		int i = nums.size()-1;
		while(!found && i > 0) {
			int prev = i - 1;
			if (nums[prev] < nums[i]) {
				found = true;
			}
			i--;
		}
		if(!found) {
			reverse(nums.begin(),nums.end());
			return;
		}
		found = false;
		int j = nums.size()-1;
		while(!found && j > i) {
			if (nums[i] < nums[j]) {
				found = true;
			}
			else {
				j--;
			}
		}
		swap(nums[i],nums[j]);
		reverse(nums.begin()+i+1,nums.end());
	}
};

int main() {
	vector<int> nums;
	nums.push_back(5);
	nums.push_back(4);
	nums.push_back(7);
	nums.push_back(5);
	nums.push_back(3);
	nums.push_back(2);
	Solution::nextPermutation(nums);
	for(auto a : nums) {
		cout << a;
	}
	cout << "FINISHED";
	return 0;
}
