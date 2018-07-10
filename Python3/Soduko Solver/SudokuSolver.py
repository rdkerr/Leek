#!/usr/bin/python
#Write a program to solve a Sudoku puzzle by filling the empty cells.
#A sudoku solution must satisfy all of the following rules:
#Each of the digits 1-9 must occur exactly once in each row.
#Each of the digits 1-9 must occur exactly once in each column.
#Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
#Empty cells are indicated by the character '.'.
import time
class Solution:
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        self.board = board
        self.nums = ['1','2','3','4','5','6','7','8','9']
        self.solve()
        self.printBoard()
        
    def printBoard(self):
        for line in self.board:
            print(*line)
        print()
        
    def findEmpty(self):
        for row in range(9):
            for col in range(9):
                if self.board[row][col] == '.':
                    return row,col
        return -1, -1

    def solve(self):
        #self.printBoard()
        #time.sleep(.1)
        row, col = self.findEmpty()
        #No empty cells remaining
        if row == -1 and col == -1:
            return True
        #Try every number in every grid
        for num in self.nums:
            if self.canPlace(row,col,num):
                self.board[row][col] = num
                if self.solve():
                    return True
                self.board[row][col] = '.'
        return False

    def canPlace(self, row, col, num):
        #check horizontal
        for c in range(9):
            if self.board[row][c] == num:
                return False
        #check vertical
        for r in range(9):
            if self.board[r][col] == num:
                return False
        #check square
        squareRow = row - row % 3
        squareCol = col - col % 3
        for r in range(squareRow,squareRow+3):
            for c in range(squareCol,squareCol+3):
                if self.board[r][c] == num:
                    return False
        return True
        
def main():
    target = [['5','3','.','.','7','.','.','.','.'],
            ['6','.','.','1','9','5','.','.','.'],
            ['.','9','8','.','.','.','.','6','.'],
            ['8','.','.','.','6','.','.','.','3'],
            ['4','.','.','8','.','3','.','.','1'],
            ['7','.','.','.','2','.','.','.','6'],
            ['.','6','.','.','.','.','2','8','.'],
            ['.','.','.','4','1','9','.','.','5'],
            ['.','.','.','.','8','.','.','7','9']]
    sol = Solution()
    sol.solveSudoku(target)
       

if __name__ == "__main__":
    main()
