/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
	var step = 0;
	var end = 0; 
	var reach = 0;
	for(var i = 0 ; i < nums.length - 1; i++) {
		reach = Math.max(reach, i + nums[i]);
		if (i == end) {
			step ++;
			end = reach;
		}
	}
    return step;
};