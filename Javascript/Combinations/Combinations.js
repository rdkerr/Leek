/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function(n, k) {
  let result = [];
  var helper = function(current, start) {
    if (current.length === k) {
      result.push(current.slice());
    } else {
      for (let i = start; i < n; i++) {
        if (current.length < k - (n - i)) break;
        current.push(i + 1);
        helper(current, i + 1);
        current.pop();
      }
    }
  }
  helper([], 0);
  return result;
};

console.log(combine(4,2))
