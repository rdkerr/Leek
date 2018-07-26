/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
	var result = [];
	backtrack(result,nums,[]);
    return result;
};

var backtrack = function(result, nums, temp) {
	if(temp.length==nums.length) {
		result.push(temp);
	}
	else {
		for (var i = 0 ;  i < nums.length ; i ++) {
			if(temp.indexOf(nums[i]) > -1) {
				continue;
			}
			temp.push(nums[i]);
			backtrack(result,nums,temp);
			temp.pop();
		}
	}
}