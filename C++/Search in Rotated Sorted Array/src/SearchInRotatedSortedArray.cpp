//============================================================================
// Name        : SearchInRotatedSortedArray.cpp
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
    static int search(vector<int>& nums, int target) {
    	if(nums.empty()) {
    		return -1;
    	}
    	int front = 0;
    	int back = nums.size() - 1;
    	int srch = (front + back) / 2;
    	while (front < back) {
    		srch = (front + back) / 2;
    		if(target > nums[srch]) {
    			if (nums[back] < target && nums[srch] <= nums[back]) {
    				back = srch;
    			}
    			else {
    				front = srch + 1;
    			}
    		}
    		else if (target < nums[srch]) {
    			if (nums[front] > target && nums[srch] >= nums[front]) {
					front = srch + 1;
				}
				else {
					back = srch;
				}
    		}
    		else {
    			return srch;
    		}
    	}
    	if (nums[srch]==target) {
    		return srch;
    	}
        return -1;
    }
};

int main() {
	int target = 3;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	int ans = Solution::search(nums, target);
	cout << ans << endl;
	return 0;
}
