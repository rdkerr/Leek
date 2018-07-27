/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
	result = [];
	indexes = [];
	for (var i = 0 ; i < strs.length ; i++) {
		var current = strs[i].split("").sort().join("");
		var ind = indexes.indexOf(current);
		if(ind < 0) {
			indexes.push(current);
			result.push([strs[i]]);
		}
		else {
			result[ind].push(strs[i]);
		}
	}
	return result;  
};

groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]);