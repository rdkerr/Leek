/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    
};

console.log(simplifyPath("/home/"));
console.log(simplifyPath("/a/./b/../../c/)");
console.log(simplifyPath("/a/../../b/../c//.//)");
console.log(simplifyPath("/a//b////c/d//././/.."));
