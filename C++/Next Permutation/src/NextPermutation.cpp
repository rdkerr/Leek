//============================================================================
// Name        : NextPermutation.cpp
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
    static void nextPermutation(vector<int>& nums) {
    	bool found = false;
    	int i = nums.size();
    	while(!found && i > 0) {
    		int prev = i - 1;
    		if (nums[prev] < nums[i]) {
    			int temp = nums[prev];
				nums[prev] = nums[i];
				nums[i] = temp;
				found = true;
    		}
    		i--;
    	}
    	if(!found) {
    		int beg = 0;
    		int end = nums.size()-1;
    		while (beg < end) {
    			int temp = nums[beg];
				nums[beg] = nums[end];
				nums[end] = temp;
				beg++;
				end--;
    		}
    	}
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
	return 0;
}
