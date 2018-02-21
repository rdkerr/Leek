/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    sorted = strs.sort(function(a,b){return a.length - b.length});
    res = "";
    if (sorted.length == 0 ) {
    	return res;
    }
    else if (sorted.length ==1) {
    	return sorted[0];
    }
    for (i = 0 ; i < sorted[0].length ; i ++) {
    	var current = sorted[0][i];
    	for (j = 1 ; j < sorted.length ; j++) {
    		if (current != sorted[j][i]) {
    			return res;
    		}
    	}
    	res += current;
    }
    return res;
};