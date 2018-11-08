/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if (n <= 3) {
    	return n;
    }
    else {
    	var a = 2;
    	var b = 3;
    	for (let i = 3 ; i < n ; i ++) {
    		let c = b;
    		b = a + b;
    		a = c;
    	}
    	return b;
    }
};

console.log(climbStairs(2));
console.log(climbStairs(3));
console.log(climbStairs(4));
console.log(climbStairs(5));
console.log(climbStairs(6));