/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
	var n = matrix.length;
    for (var i = 0 ; i < Math.floor(n / 2) ; i ++) {
    	for (var j = i ; j < n-(i+1) ; j ++){
    		var temp = matrix[i][j];
    		matrix[i][j] = matrix[(n-1)-j][i];
    		matrix[(n-1)-j][i] = matrix[(n-1)-i][(n-1)-j];
    		matrix[(n-1)-i][(n-1)-j]=matrix[j][(n-1)-i];
    		matrix[j][(n-1)-i] = temp;
    	}
    	
    }
};

var matrix = [	[1,2,3],
  				[4,5,6],
  				[7,8,9]
			];

var matrix2 =[	[ 5, 1, 9,11],
  				[ 2, 4, 8,10],
  				[13, 3, 6, 7],
  				[15,14,12,16]
			];
//console.log(matrix);
rotate(matrix);
rotate(matrix2);
console.log(matrix);
console.log(matrix2);