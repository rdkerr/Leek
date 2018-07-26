/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
	var result = [];
	nums.sort();
	backtrack(result,nums,[],new Array(nums.length).fill(false));
    return result;
};

var backtrack = function(result, nums, temp,used) {
	if(temp.length==nums.length) {
		result.push(temp.slice());
	}
	else {
		for (var i = 0 ;  i < nums.length ; i ++) {
			if(used[i] || i > 0 && nums[i] == nums[i-1] && !used[i - 1]){
				continue;
			}
			temp.push(nums[i]);
			used[i]=true;
			backtrack(result,nums,temp,used);
			temp.pop();
			used[i]=false;
		}
	}
};

console.log(permuteUnique([1,1,2]));