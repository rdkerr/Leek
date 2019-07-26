/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
  let i = 0;
  let j = 0;
  let pair = false;
  while (j < nums.length) {
    if (nums[j-1] !== nums[j]) {
      nums[i++] = nums[j];
      pair = false;
    } else {
      if (!pair) {
        pair = true;
        nums[i++] = nums[j];
      }
    }
    j++;
  }
  return i;
};

console.log(removeDuplicates([1,1,1,2,2,3]))

console.log(removeDuplicates([0,0,1,1,1,1,2,3,3]))