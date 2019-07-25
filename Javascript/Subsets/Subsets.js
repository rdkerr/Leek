/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
  let result = [];

  var helper = function(current, start) {
    result.push(current.slice())
    for (let i = start; i < nums.length; i++) {
      current.push(nums[i])
      helper(current, i + 1)
      current.pop()
    }
  }
  helper([], 0);
  return result;
};

console.log(subsets([1,2,3]))

