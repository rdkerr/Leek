/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    let col = matrix.length - 1;
    let row = 0;
    if (matrix.length === 0) return false;
    while (matrix[row][0] && matrix[row][0] < target) row++;
    row--;
    while (col > 0) {
        if (matrix[row-1][col] === target) {
            return true;
        }
        col--;
    }
    return false;
};

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false