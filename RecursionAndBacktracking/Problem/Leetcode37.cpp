#include "leetcode_problem.h"

bool Solution::solve(vector<vector<char>> &board){   
    // Run all cell in board
    for(int row = 0; row < 9; ++row){
        for(int col = 0; col < 9; ++col){
            // On empty cell
            if(board[row][col] == '.'){
                for(char number = '1'; number <= '9'; ++number){
                    // Try to put valid number
                    if(isValid(board, row, col, number)){                            
                        board[row][col] = number;
                        if(solve(board)) return true;
                        else{ // If the number is incorrect
                              // Callback and delete this cell to try another way  
                            board[row][col] = '.';   
                        }
                    }
                }
                return false;
            }
                
        }
    }
    return true;
}
    
bool Solution::isValid(vector<vector<char>>& board, int row, int col, char number){
    for(int i = 0; i < 9; ++i){
        // Check the row
        if(board[row][i] == number) return false;

        // Check the column
        if(board[i][col] == number) return false;

        // Check the submatrix
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == number) return false;
    }
        
    return true;
}

void Solution::solveSudoku(vector<vector<char>>& board) {
    solve(board);
}