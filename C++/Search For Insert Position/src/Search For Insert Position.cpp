//============================================================================
// Name        : Search.cpp
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
    static int searchInsert(vector<int>& nums, int target) {
    	if(nums.empty()) {
			return 0;
		}
		int front = 0;
		int back = nums.size() - 1;
		int srch;
		while (front < back) {
			srch = front + (back - front) / 2 ;
			if (target < nums[srch]) {
				back = srch;
			}
			else if (target > nums[srch]){
				front = srch + 1;
			}
			else {
				return srch;
			}
		}
		if (front == nums.size() - 1 && nums[front] < target) {
			return front + 1;
		}
		return front;
    }
};

int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(6);
	int target = 7;
	int ans = Solution::searchInsert(nums,target);
	cout << ans << endl;
	return 0;
}
