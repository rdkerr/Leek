/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {

};

let input = [
  [1,1,1],
  [1,0,1],
  [1,1,1]
];
let output = [
  [1,0,1],
  [0,0,0],
  [1,0,1]
];
let input2 = [
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
];
let output2 = [
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
];

setZeroes(input)
console.log("TCL: input", input)
setZeroes(input2)
console.log("TCL: input2", input2)