/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
  function search(row, col, index, visited) {
    console.log(row, col, index, visited);
    if (index === word.length) return true;
    if (row < 0 || row === board.length || col < 0 || col === board[0].length) return false;
    if (visited[`${row},${col}`]) return false;
    let found = false;
    if (board[row][col] === word[index]) {
      visited[`${row},${col}`] = true;
      found = search(row + 1, col, index + 1, visited) ||
        search(row, col + 1, index + 1, visited) ||
        search(row - 1, col, index + 1, visited) ||
        search(row, col - 1, index + 1, visited);
      visited[`${row},${col}`] = false;
    }
    return found;
  }

  for (let row = 0; row < board.length; row++) {
    for (let col = 0; col < board[0].length; col++) {
      if (word[0] === board[row][col]) {
        if (search(row, col, 0, {})) return true;
      }
    }
  }
  return false;
};

// board = [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ];
// console.log(exist(board, "ABCCED"))
// console.log(exist(board, "SEE"))
// console.log(exist(board, "ABCB"))

let board = [ ["A","B","C","E"],
              ["S","F","E","S"],
              ["A","D","E","E"]]
console.log(exist(board, "ABCESEEEFS"))