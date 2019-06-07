/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
  let n = word1.length + 1;
  let m = word2.length + 1;
  const dp = Array.from({length: n}, () => Array.from({length: m}, () => 0));
  for(let i = word1.length; i >= 0; i--) {
    for(let j = word2.length; j >= 0; j--) {
      console.log(i,j,dp)
      if(i === word1.length) {
        console.log('I',word2.length, j)
        dp[i][j] = word2.length - j;
      }
      else if(j === word2.length) {
        console.log('J',word1.length, i)
        dp[i][j] = word1.length-i;
      }
      else if(word1.charAt(i) == word2.charAt(j)) {
        console.log('=')
        dp[i][j] = dp[i+1][j+1];
      }
      else {
        console.log('ELSE')
        let replace = 1 + dp[i+1][j+1];
        let insert = 1 + dp[i][j+1];
        let remove = 1 + dp[i+1][j];
        dp[i][j] = Math.min(replace, Math.min(insert, remove));
      }
    }
  }
  return dp[0][0];
};


let word1 = 'horse';
let word2 = 'ros';
console.log(minDistance(word1,word2))
// word1 = 'intention';
// word2 = 'execution';
// console.log(minDistance(word1,word2))