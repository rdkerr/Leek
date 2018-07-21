/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
	for(var i = 0 ; i < nums.length ; i ++) {
		if(nums[i] > 0 && nums[i] <= nums.length) {
			var toSwap = nums[nums[i]-1];
			nums[nums[i]-1] = nums[i];
			nums[i] = toSwap;
			if (nums[i] != nums[nums[i]-1]) {
				i--;
			}
		}
	}
	var result = 1;
	while (nums[result - 1] == result) {
		result ++;
	}
    return result;
};