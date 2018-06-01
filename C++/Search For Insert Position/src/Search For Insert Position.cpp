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
        return 0;
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
	int ans = Solution::searchInsert(nums,target);
	cout << ans << endl;
	return 0;
}
