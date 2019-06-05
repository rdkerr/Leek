/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
  let j = nums.length-1;
  let k =0;
  for(let i = 0 ; i <nums.length;i++) {
    if(i>j) break;
    if(nums[i]==0) {
      let temp = nums[i];
      nums[i] = nums[k];
      nums[k] = temp;
      k++;
    }
    if(nums[i] == 2) {
      let temp = nums[j];
      nums[j] = nums[i];
      nums[i] = temp;
      i--;
      j--;
    }
  }
};



let nums = [1,2,2,2,2,0,0,0,1,1];
sortColors(nums)
console.log("TCL: nums", nums)
// Output: [0,0,1,1,2,2]