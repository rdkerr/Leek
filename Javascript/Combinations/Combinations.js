/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function(n, k) {
  let result = new Set();
  let numbers = Array.from({length: n}, (_, i) => i + 1);

  var helper = function(current, remaining) {
    if (current.length === k) {
      result.add(current.slice());
    } else {
      for (let i = 0; i < remaining.length; i++) {
        current.push(remaining[i]);
        let temp = remaining.slice();
        temp.splice(i,1);
        helper(current, temp);
        current.pop();
      }
    }
  }
  helper([], numbers);
  return Array.from(result);
};

console.log(combine(4,2))