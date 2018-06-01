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
    	res.push_back(-1);
    	res.push_back(-1);
    	if(nums.empty()) {
    		return res;
    	}
    	int front = 0;
    	int back = nums.size() - 1;
    	int srch;
    	while (front < back) {
    		srch = front + (back - front) / 2 ;
    		if (target <= nums[srch]) {
    			back = srch;
    		}
    		else {
    			front = srch + 1;
    		}
    	}
    	if (nums[front] != target) {
    		return res;
    	}
    	res.at(0)  = front;
    	back = nums.size() - 1;
    	while (front < back) {
    		srch = front + (back - front) / 2 + 1;
			if (target < nums[srch]) {
				back = srch - 1;
			}
			else {
				front = srch;
			}
    	}
    	res.at(1)  = back;
    	return res;
    }


};

int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(8);
	nums.push_back(10);
	int target = 8;
	vector<int> res = Solution::searchRange(nums,target);

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
