/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
  function search(row, col, index) {
    if (board[row] === undefined || word[index] !== board[row][col]) {
      return;
    }
    index++;
    if (index === word.length) return true;
    const temp = board[row][col];
    board[row][col] = true;
    let found = search(row + 1, col, index) ||
      search(row, col + 1, index) ||
      search(row - 1, col, index) ||
      search(row, col - 1, index);
      board[row][col] = temp;
    return found;
  }

  for (let row = 0; row < board.length; row++) {
    for (let col = 0; col < board[0].length; col++) {
      if (word[0] === board[row][col]) {
        if (search(row, col, 0)) return true;
      }
    }
  }
  return false;
};

let board = [ ["A","B","C","E"],
              ["S","F","E","S"],
              ["A","D","E","E"]]
console.log(exist(board, "ABCESEEEFS"))