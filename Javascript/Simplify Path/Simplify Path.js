/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    var arr = path.split('/');
    arr = arr.filter(i => i);
    var stack = [];
    for (let a of arr) {
    	if (a === '..' && stack) {
    		stack.pop();
    	} else if (a === '.') {
    		continue;
    	} else {
    		stack.push(a);
    	}
    }
    console.log(stack);
    var ans = stack.length === 0 ? '/' : '';
    for (let a of stack) {
    	ans += '/' + a;
    }
    return ans;
};
console.log(simplifyPath("/"));
console.log(simplifyPath("/home/"));
console.log(simplifyPath("/a/./b/../../c/"));
console.log(simplifyPath("/a/../../b/../c//.//"));
console.log(simplifyPath("/a//b////c/d//././/.."));
