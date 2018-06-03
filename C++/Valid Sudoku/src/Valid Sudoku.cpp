//============================================================================
// Name        : Valid.cpp
// Author      : Roger Kerr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static bool isValidSudoku(vector<vector<char>>& board) {
    	bool squares[9][9] = {0};
    	bool col[9][9] = {0};
    	for (int i = 0 ; i < 9 ; i ++) {
    		bool row[9] = {0};
    		for (int j = 0 ; j < 9 ; j ++) {
    			if(board[i][j]=='.') {
    				continue;
    			}
    			else {
    				int val = board[i][j] - 48;
    				if(row[val-1]) return false;
    				else row[val-1] = true;
    				if(col[j][val-1]) return false;
    				else col[j][val-1] = true;
    				// Check squares
    				if(squares[j/3 + i/3*3][val-1]) return false;
    				else squares[j/3 + i/3*3][val-1] = true;
    			}
    		}
    	}
        return true;
    }
};

int main() {
	vector<char> row1{ '5','3','.','.','7','.','.','.','.' };
	vector<char> row2{ '6','.','.','1','9','5','.','.','.' };
	vector<char> row3{ '.','9','8','.','.','.','.','6','.' };
	vector<char> row4{ '8','.','.','.','6','.','.','.','3' };
	vector<char> row5{ '4','.','.','8','.','3','.','.','1' };
	vector<char> row6{ '7','.','.','.','2','.','.','.','6' };
	vector<char> row7{ '.','6','.','.','.','.','2','8','.' };
	vector<char> row8{ '.','.','.','4','1','9','.','.','5' };
	vector<char> row9{ '.','.','.','.','8','.','.','7','9' };
	vector<vector<char>> board;
	board.push_back(row1);
	board.push_back(row2);
	board.push_back(row3);
	board.push_back(row4);
	board.push_back(row5);
	board.push_back(row6);
	board.push_back(row7);
	board.push_back(row8);
	board.push_back(row9);
	bool ans = Solution::isValidSudoku(board);
	cout << ans << endl;
	return 0;
}
