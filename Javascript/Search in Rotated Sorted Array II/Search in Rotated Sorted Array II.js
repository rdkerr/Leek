/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var search = function(nums, target) {
  function searchHelper(begin, end) {
    if (begin === end) return nums[begin] === target;
    const mid = Math.floor((begin + end) / 2);
    if (nums[mid] === target) {
      return true;
    } else if (target > nums[mid]) {
      if (nums[end] <= nums[begin]) {
        return searchHelper(begin, mid - 1);
      } else {
        return searchHelper(mid + 1, end);
      }
    } else {
        if (nums[end] <= nums[begin]) {
          return searchHelper(mid + 1, end);
        } else {
          return searchHelper(begin, mid - 1);
        }
    }
  }
  return searchHelper(0, nums.length)
};

console.log(search([], 5))

// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true

// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false