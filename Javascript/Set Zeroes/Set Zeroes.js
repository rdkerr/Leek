/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
  var result = [];
  for(var i=0; i<matrix.length; ++i){ // step 1
      for(var j=0; j<matrix[i].length; ++j){
          if(matrix[i][j]===0){
              result.push(i);
              result.push(j);
          }
      }
  }
  for(var k=0; k<result.length; ++k){ // step 2
      for(j=0; j<matrix[result[k]].length; ++j){
          matrix[result[k]][j] = 0;
      }
      for(i=0; i<matrix.length; ++i){
          matrix[i][result[k+1]] = 0;
      }
      ++k;
      console.log('hk',matrix)
  }
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
let input3 = [
  [1,1,1],
  [0,1,2]
];
let output3 = [
  [0,1,1],
  [0,0,0]
];

setZeroes(input)
console.log("TCL: input", input)
setZeroes(input2)
console.log("TCL: input2", input2)
setZeroes(input3)
console.log(input3)