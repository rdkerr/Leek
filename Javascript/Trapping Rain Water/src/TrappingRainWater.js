/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
	var left = 0
	var right = height.length-1;
	var leftMax = 0;
	var rightMax = 0;
	var total = 0;
	while(left < right) {
		if (height[left] < height[right]) {
			if (height[left] >= leftMax) {
				leftMax = height[left];
			}
			else {
				total +=  (leftMax - height[left]);
			}
			left ++;
		}
		else {
			if (height[right] >= rightMax) {
				rightMax = height[right];
			}
			else {
				total += (rightMax - height[right]);
			}
			right--;
		}
	}
    return total;
};