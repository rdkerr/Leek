/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    let row = matrix.length - 1;
    let col = 0;
    if (matrix.length === 0) return false;
    while (matrix[row] && matrix[row][0] && matrix[row][0] > target) row--;
    if (row < 0) return false;
    while (col < matrix[row].length) {
        if (matrix[row][col] === target) {
            return true;
        }
        col++;
    }
    return false;
};

// Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
console.log(searchMatrix(matrix, target))
// Output: true

// Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
console.log(searchMatrix(matrix, target))
// Output: false