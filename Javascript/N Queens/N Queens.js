/**
 * @param {number} n
 * @return {string[][]}
 */
var solveNQueens = function(n) {
    var res = []
    backtrack(0,res,[],n);
    var ans = [];
    for (var i = 0 ; i < res.length ; i ++) {
    	ans.push([]);
    	for (var j = 0  ; j < n ; j ++) {
    		ans[i].push(new Array(n).fill("."));
    	}
    }
    for (var i = 0 ; i < res.length ; i ++) {
    	for (var j = 0 ; j < n ; j ++) {
    		ans[i][j][res[i][j]] = 'Q';
    	}
    }
    for (var i = 0 ; i < res.length ; i ++) {
    	for (var j = 0 ; j < n ; j ++) {
    		ans[i][j] = ans[i][j].join("");
    	}
    }
    return ans;
};

var backtrack = function(col,res,temp,n) {
	if (temp.length == n) {
		res.push(temp.slice());
	}
	else {
		for(var row = 0 ; row < n ; row ++) {
			if (temp.indexOf(row) == -1) {
				if(check(temp,row,col)) {
					temp.push(row);
					backtrack(col+1,res,temp,n);
					temp.pop();
				}
			}
		}
	}
};

var check = function(temp,row,col) {
	for (var i = 0 ; i < temp.length ; i ++) {
		if (Math.abs((row - temp[i])/(col - i)) == 1) {
			return false;
		}
	}
	return true;
};

console.log(solveNQueens(4));