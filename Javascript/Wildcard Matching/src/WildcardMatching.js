/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
 var isMatch = function(s, p) {
 	if(s==null || p == null) {
 		return s==p;
 	}
 	var result = [];
 	for (var row = 0 ; row <= s.length ; row ++) {
 		result.push(new Array(p.length+1).fill(false));
 	}
 	result[0][0] = true;
 	var i = 1; 
 	while (i <= p.length && p[i-1]=='*') {
 		result[0][i] = true;
 		i++;
 	}
 	for (var row = 1 ; row <= s.length ; row ++) {
 		for (var col = 1 ; col <= p.length ; col ++) {
 			if (s[row-1] == p[col-1] || p[col-1] == "?") {
 				result[row][col] = result[row-1][col-1];
 			}
 			else if (p[col-1] == "*") {
 				result[row][col] = result[row-1][col] || result[row][col - 1];
 			}
 		}
 		
 	}
 	/**for (var row = 0 ; row <= s.length ; row ++) {
 	*	for (var col = 0 ; col <= p.length ; col ++) {
 			document.write(result[row][col]);
 	*	}
 	*	document.write("<br>");
 	*}
 	*/
 	return result[s.length][p.length];
 };