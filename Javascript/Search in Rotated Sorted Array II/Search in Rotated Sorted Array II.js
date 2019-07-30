/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var search = function(nums, target) {
  if (nums.length === 0) return false;
  if (nums.length === 1) return nums[0] === target ? true : false;
  let start = 0;
  let end = nums.length -1;
  while (start <= end) {
    const mid = parseInt((start+end)/2, 10);

    const leftEl = nums[start];
    const midEl = nums[mid];
    const rightEl = nums[end];

    if ([leftEl, midEl, rightEl].indexOf(target) > -1) return true;

    if (rightEl > midEl) {
      if (midEl < target && target < rightEl) {
        start = mid + 1;
        end--;
      } else {
        end = mid - 1;
        start++;
      }
    } else if (leftEl < midEl) {
      if (leftEl < target && target < midEl) {
        end = mid - 1;
        start++;
      } else {
        start = mid + 1;
        end--;
      }
    } else {
      start++;
      end --;
    }
  }
  return false;
  }

console.log(search([], 5))

// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true

// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false