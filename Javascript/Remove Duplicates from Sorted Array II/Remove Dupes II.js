/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
  if (nums.length <= 2) return nums.length;
  let count = 2;
  for (let i = 2; i < nums.length; i++) {
    if (nums[i] != nums[count - 2]) {
      nums[count++] = nums[i];
    }
  }
  return count;
};

console.log(removeDuplicates([1,1,1,2,2,3]))

console.log(removeDuplicates([0,0,1,1,1,1,2,3,3]))